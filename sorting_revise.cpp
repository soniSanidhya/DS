#include <iostream>
#include<fstream>
using namespace std;

void merge(int arr[], int l, int mid, int h)
{
    int n1 = (mid - l) + 1, n2 = h - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}

void merge_sort(int arr[], int l, int h)
{
    if (l >= h)
        return;
    int mid = l + (h - l) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, h);
    merge(arr, l, mid, h);
}

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int set_pivot(int arr[] , int l , int h){
    int pivot = arr[l];
    int i = l , j = h;
    while(i < j){
        while(i <=h && arr[i] <= pivot)i++;
        while(arr[j] > pivot)j--;
        if(i < j)
        swap(&arr[i] , &arr[j]);
    }
    swap(&arr[l] , &arr[j]);
    return j;
}

void quick_sort(int arr[] , int l , int h){
    if(l>=h)return;
    int p = set_pivot(arr , l , h);
    quick_sort(arr , l , p-1);
    quick_sort(arr, p+1 , h);
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt" );
    int n;
    fin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        fin>>arr[i];
    }
    // merge_sort(arr , 0 , n-1);
    quick_sort(arr, 0 , n-1);
    fout<<"\n";
    for (int i = 0; i < n; i++)
    {
        fout << arr[i] << "\t";
    }
    fin.close();
    fout.close();
    return 0;
}