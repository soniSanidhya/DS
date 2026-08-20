#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> visited;
    pq.push({a[0] + b[0], {0, 0}});
    visited.insert({0, 0});
    vector<int> ans;
    while ((int)ans.size() < k && !pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;
        ans.push_back(sum);
        if (i + 1 < n && visited.find({i + 1, j}) == visited.end())
        {
            pq.push({a[i + 1] + b[j], {i + 1, j}});
            visited.insert({i + 1, j});
        }
        if (j + 1 < n && visited.find({i, j + 1}) == visited.end())
        {
            pq.push({a[i] + b[j + 1], {i, j + 1}});
            visited.insert({i, j + 1});
        }
    }
    for (int i = 0; i < (int)ans.size(); i++)
    {
        cout << ans[i] << (i + 1 == (int)ans.size() ? "" : " ");
    }
    cout << "\n";
    return 0;
}
