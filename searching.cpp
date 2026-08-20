#include <iostream>
using namespace std;

int binarySearch(int n, int arr[] , int x)
{
    int l = 0;
    int h = n - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] == x )return mid;
        else if(arr[mid] < x){
            l= mid + 1;
        }else{
            h = mid-1;
        }
    }
    return -1;
}

int recursive_BS(int target , int arr[] , int l , int h){
    if(l > h) return -1;
    int mid = (l+h)/2;
    if(arr[mid] == target)return mid;
    else if (arr[mid] > target) return recursive_BS(target , arr , l , mid-1);
    else return recursive_BS(target , arr , mid+1 , h);
}
int main()
{
    int n , x ;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i ++){
        cin>>arr[i];
    }
    // cout<<"target: ";
    cin>>x;
    // cout<<binarySearch(n , arr ,x);
    cout<<recursive_BS(x , arr , 0 , n-1);
}