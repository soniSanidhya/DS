#include <bits/stdc++.h>
using namespace std;

int house_rober(vector<int> &val, int i, int end, vector<int> &dp)
{
    if (i > end)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int p = val[i] + house_rober(val, i + 2, end, dp);
    int q = house_rober(val, i + 1, end, dp);

    return dp[i] = max(p, q);
}

int main()
{

    int n;
    cin >> n;
    vector<int> val(n);

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    if (n == 1)
        return val[0];

    vector<int> dp1(n, -1);
    vector<int> dp2(n, -1);

    int p = house_rober(val, 0, n - 2, dp1);
    int q = house_rober(val, 1, n - 1, dp2);

    cout << max(p, q);
}