#include <iostream>
using namespace std;

class stack
{
private:
    int *arr;
    int top;
    int size;
    int capacity;

public:
    stack()
    {
        top = -1;
        size = 0;
        capacity = 1;
        arr = new int[capacity];
    }
    void resize()
    {
        capacity = 2 * capacity;
        int *newarr = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            newarr[i] = arr[i];
        }
        delete arr;
        arr = newarr;
    }
    void push(int val)
    {
        if (size == capacity)
        {
            resize();
        }
        arr[++top] = val;
        size++;
    }
    void pop()
    {
        if (size == 0)
        {
            // cout << "EMPTY\n";
        }
        else
        {
            // cout << arr[top--] << endl;
            top--;
            size--;
        }
    }
    void peek()
    {
        if (size == 0)
        {
            // cout << "EMPTY\n";
        }
        else
            cout << arr[top] << endl;
    }

    int get_top()
    {
        if (size == 0)
            return 0;
        return arr[top];
    }
    bool is_empty()
    {
        if (size == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

void nge(int arr[], int n){
    int temp[n];
    stack st;
    for(int i = n-1; i >= 0; i--){
        while(!st.is_empty() && st.get_top() <= arr[i]){
            st.pop();
        }
        temp[i] = st.is_empty() ? -1 : st.get_top();
        st.push(arr[i]);
    }
    for(int i = 0 ; i < n ; i++){
        cout<<temp[i]<<" ";
    }
}

int main()
{

    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    nge(arr , n);

    return 0;
}