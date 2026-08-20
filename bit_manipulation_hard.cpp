#include <bits/stdc++.h>
using namespace std;

vector<int> odd_times_intger(vector<int> v)
{
    int len = v.size();
    int temp = 0;
    for (int i = 0; i < len; i++)
    {
        temp ^= v[i];
    }
    int setbit = (temp & (temp - 1)) ^ temp;
    int m = 0;
    int n = 0;
    for (int i = 0; i < len; i++)
    {
        if (setbit & v[i])
        {
            m ^= v[i];
        }
        else
        {
            n ^= v[i];
        }
    }
    vector<int> res;
    if(m > n){
        res.push_back(n);
        res.push_back(m);
    }else{
        res.push_back(m);
        res.push_back(n);
    }
    return res;
}



int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(5);
    v.push_back(3);

    vector<int> res = odd_times_intger(v);
    cout<<res[0]<<"\t"<<res[1];

    return 0;
}