#include <bits/stdc++.h>
using namespace std;

// LC : 860
int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    while (i < g.size() && j < s.size())
    {
        if (g[i] <= s[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return i;
}

// LC: 455
bool lemonadeChange(vector<int> &bills)
{
    unordered_map<int, int> wallet;
    for (auto b : bills)
    {
        int t = b - 5;
        while (t > 0)
        {
            if (t >= 20 && wallet[20] > 0)
            {
                t = t - 20;
                wallet[20]--;
            }
            else if (t >= 10 && wallet[10] > 0)
            {
                t = t - 10;
                wallet[10]--;
            }
            else if (t >= 5 && wallet[5] > 0)
            {
                t = t - 5;
                wallet[5]--;
            }
            else
            {
                return false;
            }
        }
        wallet[b]++;
    }
    return true;
}

int main()
{
    return 0;
}