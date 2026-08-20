#include <iostream>
using namespace std;

int wood_cut(int n, int h , int arr[])
{
    int wood = 0;
    for(int i = 0 ; i < n; i++){
        int t = arr[i] - h;
        if(t > 0){
            wood += t;
        }
    }
    return wood;
}




int main()


{
    int t;
    cin>>t;
    while(t--){
        int n , b;
        cin>>n>>b;
        int trees[n];
        int maxH = 0;
        for(int i = 0 ; i < n ; i++){
            cin>>trees[i];
            maxH = max(maxH , trees[i]);
        }
        // cout<<maxH;
        int l = 1 , h = maxH;
        bool f = 1;
        int wood;
        int mid;
        // int sum = 0;
        // for(int i = 0 ; i < n ;i++){
        //     sum += trees[i];
        // }
        while(l <= h){
            mid = l + (h-l)/2;
            wood = wood_cut(n , mid ,trees);
            if(b == wood){
                break;
            }
            else if(b < wood){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        if(b<=wood)cout<<mid<<endl;
        else{
            cout<<-1<<endl;
        }
        
    }
    return 0;
}


// 6 9
// 20 18 15 12 10 8