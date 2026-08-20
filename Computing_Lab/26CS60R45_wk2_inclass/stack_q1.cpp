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
            cout << "EMPTY\n";
        }
        else
        {
            cout << arr[top--] << endl;
            size--;
        }
    }
    void peek()
    {
        if (size == 0)
        {
            cout << "EMPTY\n";
        }
        else
            cout << arr[top] << endl;
    }
    void is_empty()
    {
        if (size == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
};

int main()
{

    int n;
    cin >> n;
    stack st;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int x;
        if (str.compare("PUSH") == 0)
        {
            cin >> x;
            st.push(x);
        }
        else if (str.compare("POP") == 0)
        {
            st.pop();
        }
        else if (str.compare("PEEK") == 0)
        {
            st.peek();
        }
        else if (str.compare("ISEMPTY") == 0)
        {
            st.is_empty();
        }
        else
        {
            cout << "\nWRONG INPUT\n";
            i--;
        }
    }
    return 0;
}