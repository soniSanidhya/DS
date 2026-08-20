#include <iostream>
using namespace std;

class stack
{
private:
    char *arr;
    int top;
    int size;
    int capacity;

public:
    stack()
    {
        top = -1;
        size = 0;
        capacity = 1;
        arr = new char[capacity];
    }
    void resize()
    {
        capacity = 2 * capacity;
        char *newarr = new char[capacity];
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

    char get_top()
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

int main()
{

    string str;
    cin >> str;
    stack st;

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            // cout << "pushed: " << str[i] << endl;
            st.push(str[i]);
        }
        else if (st.get_top() == '(' && str[i] == ')')
        {
            // cout << "poped: " << str[i] << endl;
            st.pop();
        }
        else if (st.get_top() == '[' && str[i] == ']')
        {
            // cout << "poped: " << str[i] << endl;

            st.pop();
        }
        else if (st.get_top() == '{' && str[i] == '}')
        {
            // cout << "poped: " << str[i] << endl;

            st.pop();
        }
        else
        {
            cout << "NO\n";
            return 0;
        }
    }
    if (st.is_empty())
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}