#include <iostream>
using namespace std;

class queue
{

private:
    int front;
    int rear;
    char arr[10000];
    int size;

public:
    queue()
    {
        front = -1;
        rear = -1;
        size = 0;
    }
    void enqueue(int val)
    {
        if (size == 0)
        {
            front = 0;
        }
        // cout<<"enqueing at"<<rear+1<<" "<<val<<endl;
        arr[++rear] = val;
        size++;
    }
    void dequeue()
    {
        if (size == 0)
        {

            // cout << "EMPTY\n";
            return;
        }
        else
        {
            // cout << arr[front++] << endl;
            arr[front++];
        }
        size--;
        if (size == 0)
        {
            front = -1;
            rear = -1;
        }
    }
    char get_front()
    {
        return size == 0 ? 0 : arr[front];
    }
    void peek()
    {
        if (size == 0)
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << arr[front] << endl;
        }
    }
    bool is_empty()
    {
        return size == 0;
    }
};

int main()
{
    string str;
    cin >> str;
    queue q;
    int count[26];
    for (int i = 0; i < 26; i++)
        count[i] = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int ind = str[i] - 'a';
        if (count[ind] == 0)
        {
            q.enqueue(str[i]);
            count[ind]++;
        }
        else
        {
            q.dequeue();
        }
        if (q.is_empty())
        {
            cout << -1 << " ";
        }
        else
        {
            cout << q.get_front() << " ";
        }
    }
}
