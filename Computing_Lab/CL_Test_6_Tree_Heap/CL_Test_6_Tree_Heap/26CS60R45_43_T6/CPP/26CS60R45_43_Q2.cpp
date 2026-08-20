// CS69021 Computing Lab-1 | Test - 6
// Q2: The K-th Nearest Enemy Longship

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // k:       the k as described in the problem
    // queries: queries[i] = {x, y}, the coordinates of the i-th spotted longship
    vector<long long> kthNearest(vector<vector<int>> &queries, int k)
    {
        priority_queue<long long> pq;
        vector<long long> res;
        for(vector<int> a : queries ){
            long long t = a[0]*a[0] + a[1]*a[1];
            pq.push(t);
            if(pq.size() == k){
                res.push_back(pq.top());
                pq.pop();
            }else{
                res.push_back(-1);
            }
        }
        return res;
    }
};

// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, q;
    cin >> k >> q;

    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++)
        cin >> queries[i][0] >> queries[i][1];

    Solution sol;
    vector<long long> result = sol.kthNearest(queries, k);

    for (size_t i = 0; i < result.size(); i++)
        cout << result[i] << (i + 1 < result.size() ? ' ' : '\n');

    return 0;
}
// !-----------------------------------------
// ! Don't change this portion of the code  |
// !-----------------------------------------