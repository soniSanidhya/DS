#include <bits/stdc++.h>
using namespace std;

int count_prime(int n)
{
    vector<bool> v(n, 1);
    v[0] = v[1] = 0;
    for (int i = 2; i * i < n; i++)
    {
        for (int j = i + i; j < n; j = j + i)
        {
            v[j] = 0;
        }
    }
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i])
        {
            count++;
            cout<<i<<"\t";
        }
    }

    return count;
}

bool is_prime(int n){
    if(n == 0 || n == 1) return 0;
    if(n==2) return 1;
    for(int i = 2 ; i * i  <= n; i++){
        if(n%i == 0) {
            return 0;
        }
    }
    return 1;
    
}

void print_prime_factor(int n){
    for(int i = 1 ; i <= n/2 ; i++ ){
        if(n % i == 0){
            // cout<<"div by :"<<i<<endl;
           if(is_prime(i))cout<<i<<"\t";
        }
    }
}
int main()
{

    // int ans = count_prime(100);

    // cout << ans << endl;
    print_prime_factor(546540);
    return 0;
}