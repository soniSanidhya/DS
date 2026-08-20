================================================================================
  EVALUATION REPORT: Q4
================================================================================
Timestamp        : 2026-08-18 10:17:27
Source Code File : C:\Users\sanid\OneDrive\Desktop\Programs\DS\Computing_Lab\CL_Test_6_Tree_Heap\CL_Test_6_Tree_Heap\26CS60R45_43_T6\CPP\26CS60R45_43_Q4.cpp
Language         : C++
Compilation      : FAILED (CE)
Overall Score    : 0/0 (0.0%)
Total Test Time  : 0.000 s
--------------------------------------------------------------------------------

[COMPILATION ERROR DETAILS]
C:\Users\sanid\OneDrive\Desktop\Programs\DS\Computing_Lab\CL_Test_6_Tree_Heap\CL_Test_6_Tree_Heap\26CS60R45_43_T6\CPP\26CS60R45_43_Q4.cpp:14:37: error: expected ',' or '...' before 'vector'
   14 |     int solve(int n , int k , int i vector<pair<int,int>> &edges ){
      |                                     ^~~~~~
C:\Users\sanid\OneDrive\Desktop\Programs\DS\Computing_Lab\CL_Test_6_Tree_Heap\CL_Test_6_Tree_Heap\26CS60R45_43_T6\CPP\26CS60R45_43_Q4.cpp: In member function 'int Solution::solve(int, int, int)':
C:\Users\sanid\OneDrive\Desktop\Programs\DS\Computing_Lab\CL_Test_6_Tree_Heap\CL_Test_6_Tree_Heap\26CS60R45_43_T6\CPP\26CS60R45_43_Q4.cpp:15:17: error: 'edges' was not declared in this scope
   15 |         if(i == edges.size()) return n;
      |                 ^~~~~
C:\Users\sanid\OneDrive\Desktop\Programs\DS\Computing_Lab\CL_Test_6_Tree_Heap\CL_Test_6_Tree_Heap\26CS60R45_43_T6\CPP\26CS60R45_43_Q4.cpp:18:29: error: 'edges' was not declared in this scope
   18 |         while(k >= 0 && i < edges.size()){
      |                             ^~~~~
C:\Users\sanid\OneDrive\Desktop\Programs\DS\Computing_Lab\CL_Test_6_Tree_Heap\CL_Test_6_Tree_Heap\26CS60R45_43_T6\CPP\26CS60R45_43_Q4.cpp:19:30: error: expected primary-expression before 'int'
   19 |             min_ = min(solve(int n , k-1 , i+1,edges ) , solve(int n , k , i+1 , edges));
      |                              ^~~
C:\Users\sanid\OneDrive\Desktop\Programs\DS\Computing_Lab\CL_Test_6_Tree_Heap\CL_Test_6_Tree_Heap\26CS60R45_43_T6\CPP\26CS60R45_43_Q4.cpp:19:64: error: expected primary-expression before 'int'
   19 |             min_ = min(solve(int n , k-1 , i+1,edges ) , solve(int n , k , i+1 , edges));
      |                                                                ^~~
C:\Users\sanid\OneDrive\Desktop\Programs\DS\Computing_Lab\CL_Test_6_Tree_Heap\CL_Test_6_Tree_Heap\26CS60R45_43_T6\CPP\26CS60R45_43_Q4.cpp: In member function 'int Solution::maxMinComponentSize(int, int, std::vector<std::pair<int, int> >&)':
C:\Users\sanid\OneDrive\Desktop\Programs\DS\Computing_Lab\CL_Test_6_Tree_Heap\CL_Test_6_Tree_Heap\26CS60R45_43_T6\CPP\26CS60R45_43_Q4.cpp:26:5: warning: no return statement in function returning non-void [-Wreturn-type]
   26 |     }
      |     ^

================================================================================