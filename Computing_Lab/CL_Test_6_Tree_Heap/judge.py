#!/usr/bin/env python3
"""
================================================================================
                    AUTOMATED TEST JUDGE - COMPUTING LAB
================================================================================
A comprehensive auto-grading script to evaluate C / C++ solutions against
test cases. Features:
  - Automatic discovery of source files (C/C++) and test cases (Public/Private).
  - Time Limit Exceeded (TLE), Runtime Error (RTE), Compilation Error (CE),
    Wrong Answer (WA), and Accepted (AC) verdict detection.
  - Generates detailed per-question report files (<QID>_res.txt).
  - Terminal output with color-coded summary.
================================================================================
"""

import os
import sys
import time
import argparse
import subprocess
import re
from pathlib import Path
from datetime import datetime

# Configure UTF-8 encoding safely for Windows console / redirection
if sys.version_info >= (3, 7):
    try:
        sys.stdout.reconfigure(encoding="utf-8", errors="replace")
        sys.stderr.reconfigure(encoding="utf-8", errors="replace")
    except Exception:
        pass

# Enable ANSI colors on Windows terminals
if sys.platform == "win32":
    os.system("")

# Color Constants
GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
BLUE = "\033[94m"
MAGENTA = "\033[95m"
CYAN = "\033[96m"
BOLD = "\033[1m"
DIM = "\033[2m"
RESET = "\033[0m"


def colorize(text: str, color: str) -> str:
    return f"{color}{text}{RESET}"


def normalize_lines(text: str) -> list[str]:
    """Normalize output by splitting into non-empty stripped lines."""
    if text is None:
        return []
    lines = [line.strip() for line in text.strip().splitlines()]
    while lines and not lines[-1]:
        lines.pop()
    return lines


def format_preview(text: str, max_lines: int = 5, max_chars_per_line: int = 120) -> str:
    """Formats text for preview in result files without huge blobs."""
    if not text or not text.strip():
        return "<empty>"
    lines = text.strip().splitlines()
    preview = []
    for line in lines[:max_lines]:
        if len(line) > max_chars_per_line:
            preview.append(line[:max_chars_per_line] + f"... [truncated, length: {len(line)}]")
        else:
            preview.append(line)
    if len(lines) > max_lines:
        preview.append(f"... [{len(lines) - max_lines} more lines truncated]")
    return "\n  ".join(preview)


def compare_outputs(actual: str, expected: str) -> tuple[bool, str]:
    """
    Compares actual vs expected output.
    Returns (is_match, diff_summary).
    """
    actual_lines = normalize_lines(actual)
    expected_lines = normalize_lines(expected)

    # 1. Exact line match
    if actual_lines == expected_lines:
        return True, "Output matches expected output exactly."

    # 2. Tokenized comparison
    actual_tokens = " ".join(actual.strip().split()).split()
    expected_tokens = " ".join(expected.strip().split()).split()

    if actual_tokens == expected_tokens:
        return True, "Output matches expected output (whitespace normalized)."

    # 3. Build token-level / line-level mismatch summary
    diff_lines = []
    
    # Check for token-level difference
    for idx, (e_tok, a_tok) in enumerate(zip(expected_tokens, actual_tokens)):
        if e_tok != a_tok:
            start = max(0, idx - 2)
            end_exp = min(len(expected_tokens), idx + 3)
            end_act = min(len(actual_tokens), idx + 3)
            exp_snippet = " ".join(expected_tokens[start:end_exp])
            act_snippet = " ".join(actual_tokens[start:end_act])
            diff_lines.append(f"Mismatch at token #{idx + 1}:")
            diff_lines.append(f"  Expected near: ... {exp_snippet} ...")
            diff_lines.append(f"  Received near: ... {act_snippet} ...")
            break

    if len(expected_tokens) != len(actual_tokens):
        diff_lines.append(
            f"Token count mismatch: Expected {len(expected_tokens)} tokens, but got {len(actual_tokens)} tokens."
        )

    # Also include line-level info if useful
    max_lines = max(len(actual_lines), len(expected_lines))
    for i in range(min(max_lines, 5)):
        act = actual_lines[i] if i < len(actual_lines) else "<EOF>"
        exp = expected_lines[i] if i < len(expected_lines) else "<EOF>"
        if act != exp and len(diff_lines) < 6:
            trunc_act = act[:80] + ("..." if len(act) > 80 else "")
            trunc_exp = exp[:80] + ("..." if len(exp) > 80 else "")
            diff_lines.append(f"Line {i + 1}: Expected '{trunc_exp}' | Received '{trunc_act}'")

    return False, "\n".join(diff_lines)


class TestcaseResult:
    def __init__(self, name: str, tc_type: str, input_path: Path, output_path: Path):
        self.name = name
        self.tc_type = tc_type  # 'Public' or 'Private'
        self.input_path = input_path
        self.output_path = output_path
        self.verdict = "PENDING"  # AC, WA, TLE, RTE, CE
        self.time_seconds = 0.0
        self.return_code = 0
        self.actual_output = ""
        self.expected_output = ""
        self.error_msg = ""
        self.diff_msg = ""


class QuestionResult:
    def __init__(self, qid: str, src_path: str, lang: str):
        self.qid = qid
        self.src_path = src_path
        self.lang = lang
        self.compilation_success = False
        self.compilation_output = ""
        self.testcases: list[TestcaseResult] = []
        self.total_time = 0.0
        self.passed_count = 0
        self.total_count = 0

    @property
    def score_str(self) -> str:
        return f"{self.passed_count}/{self.total_count}"

    @property
    def pass_percentage(self) -> float:
        return (self.passed_count / self.total_count * 100.0) if self.total_count > 0 else 0.0


class Judge:
    def __init__(self, root_dir: str, src_dir: str = None, test_dir: str = None, 
                 out_dir: str = None, time_limit: float = 2.0, verbose: bool = False):
        self.root_dir = Path(root_dir).resolve()
        self.src_dir = Path(src_dir).resolve() if src_dir else self.root_dir
        self.test_dir = Path(test_dir).resolve() if test_dir else self.root_dir
        self.out_dir = Path(out_dir).resolve() if out_dir else self.root_dir / "results"
        self.time_limit = time_limit
        self.verbose = verbose

        self.out_dir.mkdir(parents=True, exist_ok=True)
        self.header_dirs = self._find_header_dirs()

    def _find_header_dirs(self) -> list[Path]:
        """Locates header include directories in workspace."""
        header_dirs = []
        for path in self.root_dir.rglob("header"):
            if path.is_dir():
                header_dirs.append(path)
        return header_dirs

    def discover_questions(self, target_q: str = None) -> list[str]:
        """Finds all question IDs (e.g. Q1, Q2, Q3, Q4) in testcases and sources."""
        q_set = set()

        for path in self.test_dir.rglob("*"):
            if path.is_dir() and re.match(r"^Q[1-9][0-9]*$", path.name, re.IGNORECASE):
                q_set.add(path.name.upper())

        for ext in ["*.cpp", "*.c"]:
            for path in self.src_dir.rglob(ext):
                m = re.search(r"Q([1-9][0-9]*)", path.stem, re.IGNORECASE)
                if m:
                    q_set.add(f"Q{m.group(1)}")

        sorted_q = sorted(
            list(q_set),
            key=lambda x: int(re.search(r"\d+", x).group(0)) if re.search(r"\d+", x) else 0
        )

        if target_q:
            target_upper = target_q.upper()
            return [q for q in sorted_q if q == target_upper]
        return sorted_q

    def find_source_file(self, qid: str) -> Path | None:
        """Finds best matching source code file for a question."""
        patterns = [f"*{qid}*.cpp", f"*{qid}*.c"]
        candidates = []
        for pat in patterns:
            for path in self.src_dir.rglob(pat):
                if path.is_file() and not path.name.endswith(".exe"):
                    candidates.append(path)

        if not candidates:
            return None

        # Prioritize files in CPP directory and student solutions over empty templates
        def sort_key(p: Path):
            score = 0
            if "CPP" in p.parts:
                score += 20
            if not p.name.startswith("_rollno"):
                score += 10
            if p.suffix.lower() == ".cpp":
                score += 5
            return -score

        candidates.sort(key=sort_key)
        return candidates[0]

    def find_testcases(self, qid: str) -> list[TestcaseResult]:
        """Finds all input and output testcase pairs for a question."""
        testcases = []

        # Look for dedicated question folder (e.g. Testcases/Testcases/Q1)
        target_dir = None
        for p in self.test_dir.rglob(qid):
            if p.is_dir() and "test" in str(p).lower():
                target_dir = p
                break

        search_dirs = [target_dir] if target_dir else [self.test_dir]

        found_inputs = []
        for s_dir in search_dirs:
            for inp_path in s_dir.rglob("*_Input.txt"):
                if qid.lower() in inp_path.name.lower() or (target_dir and inp_path.is_relative_to(target_dir)):
                    found_inputs.append(inp_path)

        # Deduplicate inputs
        unique_inputs = {}
        for inp in found_inputs:
            unique_inputs[str(inp.resolve())] = inp

        for inp_path in unique_inputs.values():
            out_candidates = [
                inp_path.parent / inp_path.name.replace("_Input.txt", "_Output.txt"),
                inp_path.parent / inp_path.name.replace("_Input.txt", "_Ouput.txt"),
                inp_path.parent / inp_path.name.replace("_input.txt", "_output.txt"),
            ]

            out_path = None
            for cand in out_candidates:
                if cand.exists():
                    out_path = cand
                    break

            if out_path:
                tc_name = inp_path.stem.replace(f"{qid}_", "").replace("_Input", "")
                tc_type = "Public" if "public" in inp_path.name.lower() else ("Private" if "private" in inp_path.name.lower() else "Testcase")

                testcases.append(TestcaseResult(
                    name=tc_name,
                    tc_type=tc_type,
                    input_path=inp_path,
                    output_path=out_path
                ))

        # Sort: Public first (1, 2, 3...), then Private (1, 2, 3...)
        def tc_sort_key(tc: TestcaseResult):
            type_order = 0 if tc.tc_type == "Public" else 1
            num_match = re.search(r"\d+", tc.name)
            num = int(num_match.group(0)) if num_match else 0
            return (type_order, num, tc.name)

        testcases.sort(key=tc_sort_key)
        return testcases

    def compile_source(self, src_path: Path, binary_path: Path) -> tuple[bool, str]:
        """Compiles a C or C++ source file."""
        is_cpp = src_path.suffix.lower() in [".cpp", ".cc", ".cxx"]
        compiler = "g++" if is_cpp else "gcc"
        std_flag = "-std=c++17" if is_cpp else "-std=c11"

        cmd = [compiler, "-O2", std_flag]

        # Add include paths
        for h_dir in self.header_dirs:
            cmd.append(f"-I{h_dir}")
        cmd.append(f"-I{src_path.parent}")
        if src_path.parent.parent.exists():
            cmd.append(f"-I{src_path.parent.parent}")

        cmd.extend([str(src_path), "-o", str(binary_path)])

        try:
            res = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
            if res.returncode == 0:
                return True, res.stderr.strip()
            else:
                return False, res.stderr.strip() if res.stderr else res.stdout.strip()
        except Exception as e:
            return False, f"Compiler execution error: {str(e)}"

    def run_testcase(self, binary_path: Path, tc: TestcaseResult) -> None:
        """Executes a testcase against the binary and checks the output."""
        try:
            with open(tc.input_path, "r", encoding="utf-8", errors="replace") as f:
                input_data = f.read()
            with open(tc.output_path, "r", encoding="utf-8", errors="replace") as f:
                tc.expected_output = f.read()
        except Exception as e:
            tc.verdict = "RTE"
            tc.error_msg = f"Failed to read test files: {str(e)}"
            return

        start_time = time.perf_counter()
        try:
            proc = subprocess.run(
                [str(binary_path)],
                input=input_data,
                capture_output=True,
                text=True,
                timeout=self.time_limit
            )
            elapsed = time.perf_counter() - start_time
            tc.time_seconds = elapsed
            tc.return_code = proc.returncode
            tc.actual_output = proc.stdout

            if proc.returncode != 0:
                tc.verdict = "RTE"
                tc.error_msg = f"Non-zero exit code: {proc.returncode}\nStderr: {proc.stderr.strip()}"
            else:
                is_match, diff = compare_outputs(tc.actual_output, tc.expected_output)
                if is_match:
                    tc.verdict = "AC"
                else:
                    tc.verdict = "WA"
                    tc.diff_msg = diff

        except subprocess.TimeoutExpired:
            tc.time_seconds = self.time_limit
            tc.verdict = "TLE"
            tc.error_msg = f"Execution exceeded time limit of {self.time_limit:.2f}s"
        except Exception as e:
            tc.time_seconds = time.perf_counter() - start_time
            tc.verdict = "RTE"
            tc.error_msg = f"Execution error: {str(e)}"

    def write_res_file(self, q_res: QuestionResult) -> tuple[Path, Path]:
        """
        Writes the comprehensive result file (.res and _res.txt) for a question.
        Returns paths of created files.
        """
        res_file_results = self.out_dir / f"{q_res.qid}_res.txt"
        res_file_root = self.root_dir / f"{q_res.qid}_res.txt"
        res_file_dotres = self.out_dir / f"{q_res.qid}.res"

        lines = []
        lines.append("=" * 80)
        lines.append(f"  EVALUATION REPORT: {q_res.qid}")
        lines.append("=" * 80)
        lines.append(f"Timestamp        : {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
        lines.append(f"Source Code File : {q_res.src_path}")
        lines.append(f"Language         : {q_res.lang}")
        lines.append(f"Compilation      : {'SUCCESS' if q_res.compilation_success else 'FAILED (CE)'}")
        lines.append(f"Overall Score    : {q_res.score_str} ({q_res.pass_percentage:.1f}%)")
        lines.append(f"Total Test Time  : {q_res.total_time:.3f} s")
        lines.append("-" * 80)

        if not q_res.compilation_success:
            lines.append("\n[COMPILATION ERROR DETAILS]")
            lines.append(q_res.compilation_output)
            lines.append("\n" + "=" * 80)
            content = "\n".join(lines)
            for fpath in [res_file_results, res_file_root, res_file_dotres]:
                with open(fpath, "w", encoding="utf-8") as f:
                    f.write(content)
            return res_file_results, res_file_root

        # Summary Table
        lines.append("\n[TESTCASE SUMMARY TABLE]")
        lines.append(f"{'#':<4} | {'Testcase Name':<32} | {'Type':<8} | {'Verdict':<8} | {'Time (s)':<10} | {'Status'}")
        lines.append("-" * 80)

        for i, tc in enumerate(q_res.testcases, 1):
            status_desc = "Passed" if tc.verdict == "AC" else tc.verdict
            lines.append(f"{i:<4} | {tc.name:<32} | {tc.tc_type:<8} | {tc.verdict:<8} | {tc.time_seconds:<10.3f} | {status_desc}")

        lines.append("-" * 80)

        # Detailed Breakdown
        lines.append("\n[DETAILED TESTCASE BREAKDOWN]")
        for i, tc in enumerate(q_res.testcases, 1):
            lines.append("\n" + "-" * 40)
            lines.append(f"Testcase #{i}: {tc.name} ({tc.tc_type})")
            lines.append(f"Verdict     : {tc.verdict}")
            lines.append(f"Time        : {tc.time_seconds:.3f} s")
            lines.append(f"Input File  : {tc.input_path}")
            lines.append(f"Output File : {tc.output_path}")

            if tc.verdict == "AC":
                lines.append("Result      : PASSED")
            elif tc.verdict == "WA":
                lines.append("Result      : WRONG ANSWER")
                lines.append("Diff Summary:")
                for diff_line in tc.diff_msg.splitlines():
                    lines.append(f"  {diff_line}")
                lines.append(f"Expected Output Preview:\n  {format_preview(tc.expected_output)}")
                lines.append(f"Actual Program Output Preview:\n  {format_preview(tc.actual_output)}")
            elif tc.verdict == "TLE":
                lines.append("Result      : TIME LIMIT EXCEEDED")
                lines.append(f"Details     : {tc.error_msg}")
            elif tc.verdict == "RTE":
                lines.append("Result      : RUNTIME ERROR")
                lines.append(f"Details     : {tc.error_msg}")

        lines.append("\n" + "=" * 80)
        lines.append("  END OF REPORT")
        lines.append("=" * 80 + "\n")

        content = "\n".join(lines)
        for fpath in [res_file_results, res_file_root, res_file_dotres]:
            with open(fpath, "w", encoding="utf-8") as f:
                f.write(content)

        return res_file_results, res_file_root

    def evaluate_question(self, qid: str) -> QuestionResult:
        """Evaluates a single question against all test cases."""
        print(f"\n{BOLD}{CYAN}[>] Evaluating {qid}...{RESET}")
        src_path = self.find_source_file(qid)

        if not src_path:
            print(f"  {colorize('[x] Error:', RED)} No source file found for {qid}")
            q_res = QuestionResult(qid, "Not Found", "Unknown")
            q_res.compilation_output = f"No source file matching {qid} found."
            self.write_res_file(q_res)
            return q_res

        lang = "C++" if src_path.suffix.lower() in [".cpp", ".cc"] else "C"
        q_res = QuestionResult(qid, str(src_path), lang)
        print(f"  Source : {colorize(str(src_path), BLUE)} ({lang})")

        # Compile
        bin_path = self.out_dir / f"bin_{qid}.exe"
        print(f"  Compile: ", end="", flush=True)
        t_comp_start = time.perf_counter()
        success, comp_out = self.compile_source(src_path, bin_path)
        t_comp = time.perf_counter() - t_comp_start
        q_res.compilation_success = success
        q_res.compilation_output = comp_out

        if not success:
            print(f"{colorize('FAILED (CE)', RED)} [{t_comp:.2f}s]")
            if self.verbose:
                print(f"{RED}{comp_out}{RESET}")
            self.write_res_file(q_res)
            return q_res

        print(f"{colorize('SUCCESS', GREEN)} [{t_comp:.2f}s]")

        # Test cases
        testcases = self.find_testcases(qid)
        q_res.testcases = testcases
        q_res.total_count = len(testcases)

        if not testcases:
            print(f"  {colorize('[!] Warning:', YELLOW)} No test cases found for {qid}")
            self.write_res_file(q_res)
            if bin_path.exists():
                try:
                    bin_path.unlink()
                except Exception:
                    pass
            return q_res

        print(f"  Running {len(testcases)} test cases (Timeout: {self.time_limit:.1f}s):")
        total_time = 0.0
        passed = 0

        for i, tc in enumerate(testcases, 1):
            self.run_testcase(bin_path, tc)
            total_time += tc.time_seconds

            if tc.verdict == "AC":
                passed += 1
                verdict_col = colorize("[AC] ", GREEN)
            elif tc.verdict == "WA":
                verdict_col = colorize("[WA] ", RED)
            elif tc.verdict == "TLE":
                verdict_col = colorize("[TLE]", YELLOW)
            else:
                verdict_col = colorize("[RTE]", MAGENTA)

            tc_label = f"[{tc.tc_type}] {tc.name}"
            print(f"    #{i:02d} {tc_label:<32}: {verdict_col} ({tc.time_seconds:.3f}s)")
            
            if self.verbose and tc.verdict != "AC":
                if tc.diff_msg:
                    print(f"         {colorize(tc.diff_msg, YELLOW)}")
                if tc.error_msg:
                    print(f"         {colorize(tc.error_msg, RED)}")

        q_res.passed_count = passed
        q_res.total_time = total_time

        # Cleanup binary
        if bin_path.exists():
            try:
                bin_path.unlink()
            except Exception:
                pass

        # Write result files
        res_main, res_root = self.write_res_file(q_res)
        print(f"  Result Saved: {colorize(str(res_root.name), GREEN)} (in results/ & root)")

        return q_res

    def run_all(self, target_q: str = None):
        """Runs the judge across all questions or a targeted question."""
        print("=" * 80)
        print(f"{BOLD}{MAGENTA}  COMPUTING LAB AUTOMATED JUDGE{RESET}")
        print(f"  Workspace : {self.root_dir}")
        print(f"  Time Limit: {self.time_limit:.1f}s per testcase")
        print("=" * 80)

        questions = self.discover_questions(target_q)
        if not questions:
            print(f"{colorize('No questions found to judge!', RED)}")
            return

        print(f"Discovered Questions: {', '.join(questions)}")

        results = []
        for qid in questions:
            q_res = self.evaluate_question(qid)
            results.append(q_res)

        # Print Final Summary Table
        print("\n" + "=" * 80)
        print(f"{BOLD}{MAGENTA}  FINAL EVALUATION SUMMARY{RESET}")
        print("=" * 80)
        print(f"{'Question':<10} | {'Language':<8} | {'Compilation':<13} | {'Passed / Total':<16} | {'Pass %':<10} | {'Total Time'}")
        print("-" * 80)

        grand_total_passed = 0
        grand_total_count = 0
        grand_total_time = 0.0

        for r in results:
            comp_status = colorize("SUCCESS", GREEN) if r.compilation_success else colorize("FAILED (CE)", RED)
            score = f"{r.passed_count}/{r.total_count}"
            pass_pct = f"{r.pass_percentage:5.1f}%"
            time_str = f"{r.total_time:.3f} s"

            if r.compilation_success:
                if r.passed_count == r.total_count and r.total_count > 0:
                    score_col = colorize(score, GREEN)
                    pct_col = colorize(pass_pct, GREEN)
                elif r.passed_count > 0:
                    score_col = colorize(score, YELLOW)
                    pct_col = colorize(pass_pct, YELLOW)
                else:
                    score_col = colorize(score, RED)
                    pct_col = colorize(pass_pct, RED)
            else:
                score_col = colorize(score, RED)
                pct_col = colorize(pass_pct, RED)

            print(f"{r.qid:<10} | {r.lang:<8} | {comp_status:<22} | {score_col:<25} | {pct_col:<19} | {time_str}")

            grand_total_passed += r.passed_count
            grand_total_count += r.total_count
            grand_total_time += r.total_time

        print("-" * 80)
        overall_pct = (grand_total_passed / grand_total_count * 100.0) if grand_total_count > 0 else 0.0
        print(f"{BOLD}{'OVERALL':<10} | {'-':<8} | {'-':<13} | {grand_total_passed}/{grand_total_count:<14} | {overall_pct:5.1f}%    | {grand_total_time:.3f} s{RESET}")
        print("=" * 80)
        print(f"\n{BOLD}Result files generated for each question:{RESET}")
        for r in results:
            print(f"  * {r.qid}: {self.root_dir / f'{r.qid}_res.txt'} (and {self.out_dir / f'{r.qid}_res.txt'})")
        print()


def main():
    parser = argparse.ArgumentParser(
        description="Automated Judge for Computing Lab Programs",
        formatter_class=argparse.RawTextHelpFormatter
    )
    parser.add_argument(
        "-q", "--question",
        type=str,
        default=None,
        help="Specific question to judge (e.g. Q1, Q2, Q3, Q4). If omitted, judges all questions."
    )
    parser.add_argument(
        "-t", "--time-limit",
        type=float,
        default=2.0,
        help="Time limit per testcase in seconds (default: 2.0s)."
    )
    parser.add_argument(
        "--src-dir",
        type=str,
        default=None,
        help="Directory containing source files (default: auto-discover from workspace)."
    )
    parser.add_argument(
        "--test-dir",
        type=str,
        default=None,
        help="Directory containing testcases (default: auto-discover from workspace)."
    )
    parser.add_argument(
        "--out-dir",
        type=str,
        default=None,
        help="Directory where results will be stored (default: ./results)."
    )
    parser.add_argument(
        "-v", "--verbose",
        action="store_true",
        help="Enable verbose output showing mismatches and compiler diagnostics."
    )

    args = parser.parse_args()

    judge = Judge(
        root_dir=os.getcwd(),
        src_dir=args.src_dir,
        test_dir=args.test_dir,
        out_dir=args.out_dir,
        time_limit=args.time_limit,
        verbose=args.verbose
    )

    judge.run_all(target_q=args.question)


if __name__ == "__main__":
    main()
