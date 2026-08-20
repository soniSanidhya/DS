#include <iostream>
using namespace std;

class max_heap
{
public:
    int *arr;
    int cap;
    int size;
    heap()
    {
        cap = 1;
        size = 0;
        arr = new int[cap];
    }
    void resize()
    {
        cap *= 2;
        int *newarr = new int[cap];
        for (int i = 0; i < size; i++)
        {
            newarr[i] = arr[i];
        }
        delete arr;
        arr = newarr;
    }
    int left_child(int i)
    {
        return 2 * i + 1;
    }

    int right_child(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    void insert(int val)
    {
        int i = size++;
        if (size == cap)
            resize();
        arr[i] = val;

        while (i >= 0 && parent(i) >= 0 && arr[i] > arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void print_heap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
    void heapify(int i, int n)
    {

        int max = i;
        if (left_child(i) < n && arr[max] < arr[left_child(i)])
        {
            max = left_child(i);
        }
        if (right_child(i) < n && arr[max] < arr[right_child(i)])
        {
            max = right_child(i);
        }
        if (i != max)
        {
            swap(arr[i], arr[max]);
            heapify(max, size);
        }
    }
    bool empty()
    {
        return size == 0;
    }
    int extract_root()
    {
        int temp = arr[0];
        arr[0] = arr[--size];
        heapify(0, size);
        return temp;
    }
};

class min_heap
{
public:
    int *arr;
    int cap;
    int size;
    heap()
    {
        cap = 1;
        size = 0;
        arr = new int[cap];
    }
    void resize()
    {
        cap *= 2;
        int *newarr = new int[cap];
        for (int i = 0; i < size; i++)
        {
            newarr[i] = arr[i];
        }
        delete arr;
        arr = newarr;
    }
    int left_child(int i)
    {
        return 2 * i + 1;
    }

    int right_child(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    void insert(int val)
    {
        int i = size++;
        if (size == cap)
            resize();
        arr[i] = val;

        while (i >= 0 && parent(i) >= 0 && arr[i] < arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void print_heap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
    void heapify(int i, int n)
    {

        int max = i;
        if (left_child(i) < n && arr[max] > arr[left_child(i)])
        {
            max = left_child(i);
        }
        if (right_child(i) < n && arr[max] > arr[right_child(i)])
        {
            max = right_child(i);
        }
        if (i != max)
        {
            swap(arr[i], arr[max]);
            heapify(max, size);
        }
    }
    bool empty()
    {
        return size == 0;
    }
    int extract_root()
    {
        int temp = arr[0];
        arr[0] = arr[--size];
        heapify(0, size);
        return temp;
    }
};

int main()
{
    int n;
    int m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    min_heap h;
    int merged[m * n];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        h.insert(arr[i][0]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {

            merged[k++] = h.extract_root();
                h.insert(arr[i][j]);
        }
    }
    while(!h.empty()){
        merged[k++] = h.extract_root();
    }

    for(int i = 0 ; i < m*n ; i++){
        cout<<merged[i]<<"\t";
    }

    return 0;
}