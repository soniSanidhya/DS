#include <bits/stdc++.h>
using namespace std;

int n_queen(int col[], int ld[], int ud[], int row, int n)
{
    if (row == n) return 1;

    int cnt = 0;

    for (int c = 0; c < n; c++)
    {
        if (col[c] == 0 && ld[row + c] == 0 && ud[n - 1 + c - row] == 0)
        {
            col[c] = 1;
            ld[row + c] = 1;
            ud[n - 1 + c - row] = 1;

            cnt += n_queen(col, ld, ud, row + 1, n);

            col[c] = 0;
            ld[row + c] = 0;
            ud[n - 1 + c - row] = 0;
        }
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;

    int col[n] = {0};
    int ld[2 * n - 1] = {0};
    int ud[2 * n - 1] = {0};

    cout << n_queen(col, ld, ud, 0, n);
}