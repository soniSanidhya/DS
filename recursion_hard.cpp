#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int l = 0;
    int h = s.length() - 1;
    while (l < h)
    {
        if (s[l] != s[h])
            return false;
        l++;
        h--;
    }
    return true;
}

void plaindrome_partioning(int ind, string str, vector<vector<string>> &res, vector<string> &temp)
{
    if (ind == str.length())
    {
        res.push_back(temp);
        return;
    }

    for (int i = ind; i < str.length(); i++)
    {
        string s = str.substr(ind, i - ind + 1);

        if (isPalindrome(s))
        {
            temp.push_back(s);
            plaindrome_partioning(i + 1, str, res, temp);
            temp.pop_back();
        }
    }
    return;
}
bool dfs(string str, int ind, vector<vector<char>> board, int x, int y)
{
    if (str.length() == ind)
        return true;
    if (x < 0 || x >= (int)board.size() || y < 0 || y >= (int)board[0].size())
        return false;
    if (str[ind] != board[x][y])
        return false;
    bool res = false;
    char temp = board[x][y];
    board[x][y] = '#';
    res = dfs(str, ind + 1, board, x + 1, y) ||
          dfs(str, ind + 1, board, x - 1, y) ||
          dfs(str, ind + 1, board, x, y + 1) ||
          dfs(str, ind + 1, board, x, y - 1);
    board[x][y] = temp;
    return res;
}

bool word_search(string str, vector<vector<char>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (dfs(str, 0, board, i, j))
            {
                return true;
            }
        }
    }
    return false;
}

void mark(int n, int add, int x, int y, vector<string> &board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != 'Q')
            {
                if (i == x || j == y || (x - y) == (i - j) || (x + y) == (i + j))
                {
                    board[i][j] += add;
                }
            }
        }
    }
}

void NQueens(int n, int ind, vector<vector<string>> &board_set, vector<string> &board, vector<int> &col, vector<int> diag1, vector<int> diag2)
{
    if (ind == n)
    {
        board_set.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (col[i] == 1 || diag1[ind + i] == 1 || diag2[n - 1 + ind - i] == 1)
            continue;

        board[ind][i] = 'Q';
        col[i] = 1;
        diag1[ind + i] = 1;
        diag2[n - 1 + ind - i] = 1;
        NQueens(n, ind + 1, board_set, board, col, diag1, diag2);
        board[ind][i] = '.';
        col[i] = 0;
        diag1[ind + i] = 0;
        diag2[n - 1 + ind - i] = 0;
    }
}

void ratInMaze(vector<vector<int>> &maze, vector<vector<char>> &paths, vector<char> &path, int x, int y)
{
    if (x == maze.size() - 1 && y == maze.size() - 1)
    {
        paths.push_back(path);
        return;
    }
    if (x >= maze.size() || y >= maze.size() || x < 0 || y < 0)
        return;
    if (maze[x][y] == 0)
        return;
    maze[x][y] = 0;
    path.push_back('U');
    ratInMaze(maze, paths, path, x - 1, y);
    path.pop_back();
    path.push_back('R');
    ratInMaze(maze, paths, path, x, y + 1);
    path.pop_back();
    path.push_back('D');
    ratInMaze(maze, paths, path, x + 1, y);
    path.pop_back();
    path.push_back('L');
    ratInMaze(maze, paths, path, x, y - 1);
    path.pop_back();
    maze[x][y] = 1;
}

// bool word_break(int ind , string str , vector<string> dict , string curr){
//     if(ind == str.size()){
//         return true;
//     }
//     int j = 0;

//     while(str[ind] == curr[j]) {
//         ind++;
//         j++;
//     }
//     for(int i = 0 ; i < dict.size() ; i++){
//         if(str[ind] == dict[i][0] ){

//         }
//     }
// }

bool is_valid_sudoku(vector<vector<char>> &sudoku, char num, int x, int y)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[x][i] == num || sudoku[i][y] == num || sudoku[3 * (x / 3) + (i % 3)][3 * (y / 3) + ((i / 3))] == num)
            return false;
    }
    return true;
}

bool sudoku_solver(vector<vector<char>> &sudoku, int x, int y)
{
    
    if (y == 9)
    {
       return sudoku_solver(sudoku , x+1 , 0);
    }
    if (x == 9 )
        return true;
    if (sudoku[x][y] != '.')
        return sudoku_solver(sudoku, x, y + 1);
    ;
    for (char i = '1'; i <= '9'; i++)
    {

        if (is_valid_sudoku(sudoku, i, x, y))
        {
            // cout << i << "\t" << x << "\t" << y << endl;
            sudoku[x][y] = i;
            if(sudoku_solver(sudoku, x, y + 1)) return true;
            sudoku[x][y] = '.';

        }
    }
    return false;
}
int main()
{
    //    { string s = "nitin";
    //     vector<vector<string>> res;
    //     vector<string> temp;
    //     plaindrome_partioning(0, s, res, temp);
    //     for (int i = 0; i < res.size(); i++)
    //     {
    //         for (int j = 0; j < res[i].size(); j++)
    //         {
    //             cout << res[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     }
    // vector<vector<char>> board = {{'A', 'B', 'F', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // set<vector<int>> isVisited;
    // set<vector<int>> matched;
    // cout << "hi" << endl;
    // cout << word_search("SFBA", board);
    // int n = 4;
    // vector<vector<string>> board_set;
    // vector<string> board(n, string(n, '.'));
    // vector<int> col(n, 0);
    // vector<int> diag1(2 * n - 1, 0);
    // vector<int> diag2(2 * n - 1, 0);
    // NQueens(n, 0, board_set, board , col , diag1, diag2);
    // for (int i = 0; i < board_set.size(); i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << board_set[i][j] << endl;
    //     }
    //     cout << endl;
    // }

    //     vector<vector<int>> maze = {{1, 0, 0, 0 },
    //                                 {1, 1, 0, 1 },
    //                                 {1, 1, 0, 0 },
    //                                 {0, 1, 1, 1 }};
    //     vector<vector<char>> paths;
    //     vector<char> path;
    //     ratInMaze(maze , paths , path , 0 ,0  );
    // for (int i = 0; i < paths.size(); i++)
    //     {
    //         for (int j = 0; j < paths[i].size(); j++)
    //         {
    //             cout << paths[i][j];
    //         }
    //         cout << endl;
    //     }
    vector<vector<vector<char>>> solved;
    vector<vector<char>> sudoku = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                   {'4', '.', '8', '8', '6', '3', '.', '.', '1'},
                                   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                   {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    sudoku_solver(sudoku, 0, 0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

// 00 01 02 03 04 05 06 07 08
// 10 11 12 13 14 15 16 17 18
// 20 21 22 23 24 25 26 27 28
// 30 31 32 33 34 35 36 37 38
// 40 41 42 43 44 45 46 47 48
// 50 51 52 53 54 55 56 57 58
// 60 61 62 63 64 65 66 67 68
// 70 71 72 73 74 75 76 77 78
// 80 81 82 83 84 85 86 87 88