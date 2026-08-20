#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int num, int goal)
{
    int temp = num ^ goal;
    int count = 0;
    while (temp)
    {
        temp &= (temp - 1);
        count++;
    }
    return count;
}

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = 1 << nums.size();
    vector<vector<int>> powerSet;
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        vector<int> subset;
        while (t < nums.size())
        {
            if (i & (1 << t))
            {
                subset.push_back(nums[t]);
            }
            t++;
        }
        powerSet.push_back(subset);
    }
    return powerSet;
}

int ranged_xor(int l, int r)
{
    int temp1 = (-1);   
}

int main()
{
    // cout<<minBitFlips(3 , 4);
    vector<int> v = {1, 2, 3};
    vector<vector<int>> pow = subsets(v);
    for (int i = 0; i < pow.size(); i++)
    {
        for (int j = 0; j < pow[i].size(); j++)
        {
            cout << pow[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}