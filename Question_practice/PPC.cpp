#include <bits/stdc++.h>
using namespace std;

int min_wastage(vector<int> &curr, vector<int> pieces, int len, int i)
{
    if (len == 0)
    {
        for (int a : curr)
        {
            cout << a << "\t";
        }
        cout<<endl;
        return 0;
    }
    if (i == pieces.size())
    {
        return len;
    }
    curr.push_back(pieces[i]);
    int min1, min2;
    if ((len - pieces[i]) >= 0)
        min_wastage(curr, pieces, len - pieces[i], i + 1);
    curr.pop_back();
    min2 = min_wastage(curr, pieces, len, i + 1);
    return min1 < min2 ? min1 : min2;
}

int main()
{
    vector<int> curr;
    vector<int> pieces = {1, 2, 4, 8, 5, 3};
    cout << min_wastage(curr, pieces, 15, 0);
    cout << endl;
    for (int a : curr)
    {
        cout << a << "\t";
    }

    return 0;
}