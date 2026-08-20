#include <iostream>
#include <fstream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 1 + i * 2;
    int right = 2 + i * 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
int main()
{

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        fin >> arr[i];
    }
    // merge_sort(arr , 0 , n-1);
    heap_sort(arr, n);
    fout << "\n";
    for (int i = 0; i < n; i++)
    {
        fout << arr[i] << "\t";
    }
    fin.close();
    fout.close();
    return 0;
}