#include <iostream>
#include <fstream>
using namespace std;

void merge(int arr[], int l, int mid, int h, int *count)
{
    int n1 = mid - l + 1, n2 = h - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[i + l];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {

            arr[k++] = left[i++];
        }
        else if (right[j] < left[i])
        {
            int te = n1 - i;
            arr[k++] = right[j++];
            *count += te;
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
    // cout<<*count<<endl;
}

void count_inversion(int arr[], int l, int h, int *count)
{
    if (l >= h)
        return;
    int mid = l + (h - l) / 2;
    count_inversion(arr, l, mid, count);
    count_inversion(arr, mid + 1, h, count);
    merge(arr, l, mid, h, count);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int set_pivot(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l + 1;
    int j = h;
    while (i <= j)
    {
        while (i <= h && arr[i] <= pivot)
            i++;
        while (j >= l && arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }

    swap(&arr[j], &arr[l]);
    return j;
}

int quick_select(int arr[], int l, int h, int k)
{

    if (l >= h)
        return arr[l];
    int x = set_pivot(arr, l, h);
    if (x == k - 1)
        return arr[x];
    else if (x < k - 1)
    {
        return quick_select(arr, x + 1, h, k);
    }
    else
    {
        return quick_select(arr, l, x - 1, k);
    }
    return -1;
}

int main()
{
    ifstream fin("../input.txt");
    ofstream fout("../output.txt");
    int t;
    fin >> t;
    while (t--)
    {
        int n, k;
        fin >> n;
        fin >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            fin >> arr[i];
        }
        int count = 0;
        // count_inversion(arr, 0, n - 1, &count);

        fout << quick_select(arr, 0, n - 1, k) << endl;
    }
    fin.close();
    fout.close();
    return 0;
}