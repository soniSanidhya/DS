#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[min])
    {
        min = left;
    }
    if (right < n && arr[right] > arr[min])
    {
        min = right;
    }
    if (i != min)
    {
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        heapify(arr, n, min);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = (n - 1); i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i - 1, 0);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int set_pivot(int arr[], int l, int h)
{
    int p = arr[l];
    int i = l + 1;
    int j = h;

    while (i <= j)
    {
        while (i <= h && arr[i] < p)
            i++;
        while (j >= l && arr[j] > p)
            j--;
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void quick_sort(int arr[], int l, int h)
{
    if (l >= h)
        return;
    int p = set_pivot(arr, l, h);
    quick_sort(arr, l, p - 1);
    quick_sort(arr, p + 1, h);
}

void merge(int arr[], int l, int mid, int h)
{
    int n = (h - l) + 1;
    int temp[n];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= h)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= h)
    {
        temp[k++] = arr[j++];
    }
    for(int o = 0 ; o < n ; o++){
        arr[o+l] = temp [o];
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

int main()
{
    int n = 6;
    int arr[] = {7, 10, 4, 3, 20, 15};
    heap_sort(arr, n);
    // quick_sort(arr, 0, n - 1);
    // merge_sort(arr, 0, n - 1);

    for (int a : arr)
    {
        cout << a << "\t";
    }
    return 0;
}