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

class queue
{
private:
    stack st1;
    stack st2;
    int size;

public:
    queue()
    {
        size = 0;
    }
    void enqueue(int val)
    {
        while (!st1.is_empty())
        {
            st2.push(st1.get_top());
            st1.pop();
        }
        st1.push(val);
        while (!st2.is_empty())
        {
            st1.push(st2.get_top());
            st2.pop();
        }
        size++;
    }
    void dequeue()
    {
        if (st1.is_empty())
        {
            cout << "EMPTY\n";
            return;
        }
        cout << st1.get_top()<<endl;
        st1.pop();
        size--;
    }
};

int main()
{
    int n;
    cin >> n;
    queue q;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int x;
        if (str.compare("ENQUEUE") == 0)
        {
            cin >> x;
            q.enqueue(x);
        }
        else if (str.compare("DEQUEUE") == 0)
        {
            q.dequeue();
        }
        else
        {
            cout << "\nWRONG INPUT\n";
            i--;
        }
    }
}