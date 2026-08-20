#include <iostream>
using namespace std;

class queue
{

private:
    int front;
    int rear;
    int arr[10000];
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
        if(size == 0){
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

            cout << "EMPTY\n";
            return;
        }
        else
        { 
            cout << arr[front++] << endl;
        }
        size--;
        if(size == 0){
            front = -1;
            rear = -1;
        }
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
        else if (str.compare("FRONT") == 0)
        {
            q.peek();
        }
        else if (str.compare("ISEMPTY") == 0)
        {
            q.is_empty();
        }
        else
        {
            cout << "\nWRONG INPUT\n";
            i--;
        }
    }
    return 0;
}