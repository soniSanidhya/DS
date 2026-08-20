#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    if (!(cin >> n)) return 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++)
    {
        long long val;
        cin >> val;
        pq.push(val);
    }
    if (n <= 1)
    {
        cout << 0 << "\n";
        return 0;
    }
    long long totalCost = 0;
    while (pq.size() > 1)
    {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        long long cost = first + second;
        totalCost += cost;
        pq.push(cost);
    }
    cout << totalCost << "\n";
    return 0;
}
