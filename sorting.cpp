#include <iostream>
using namespace std;
void merge(int arr[], int l, int mid, int h)
{
	int i = l;
	int j = mid + 1;
	int k = 0;
	int temp[(h - l) + 1];

	while (i <= mid && j <= h)
	{
		if (arr[i] < arr[j])
		{

			temp[k] = arr[i];
			i++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}
	while (j <= h)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}
	k = 0;
	int start = l;
	while (start <= h)
	{
		arr[start] = temp[k];
		start++;
		k++;
	}
	return;
}
void mergeSort(int arr[], int l, int h)
{
	if (l == h)
		return;
	int mid = (l + h) / 2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid + 1, h);
	merge(arr, l, mid, h);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int n, int arr[])
{

	for (int i = 0; i < n - 1; i++)
	{
		bool f = 1;
		for (int j = 0; j < n - i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				f = 0;
			}
		}
		if (f)
			return;
	}
}

void selectionSort(int n, int arr[])
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			min = arr[j] > arr[min] ? min : j;
		}
		if(i != min){
			swap(&arr[i] , &arr[min]);
		}
	}
}

void insertionSort(int n ,int arr[]){
	for(int i = 1 ; i < n ; i++){	
		int key = arr[i];
		int j = i-1;
		while(j>-1 && arr[j] > key){
			
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
int main()
{
	int arr[] = {1, 2, 4, 5, 7, 4, 1, 2, 6, 9};
	int n = 10;
	// mergeSort(arr , 0 , 9);
	// bubbleSort(n, arr);
	// selectionSort(n , arr);
	insertionSort(n , arr);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	return 0;
}
