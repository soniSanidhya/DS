#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    if (!(cin >> q)) return 0;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            if (max_heap.empty() || x <= max_heap.top())
            {
                max_heap.push(x);
            }
            else
            {
                min_heap.push(x);
            }
            if (max_heap.size() > min_heap.size() + 1)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            else if (min_heap.size() > max_heap.size())
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
        else if (type == 2)
        {
            if (max_heap.size() > min_heap.size())
            {
                cout << fixed << setprecision(1) << (double)max_heap.top() << "\n";
            }
            else
            {
                double med = (max_heap.top() + min_heap.top()) / 2.0;
                cout << fixed << setprecision(1) << med << "\n";
            }
        }
    }
    return 0;
}
