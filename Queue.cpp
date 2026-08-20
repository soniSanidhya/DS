#include <iostream>
using namespace std;

class Queue
{
private:
    int rear;
    int front;
    int *arr;
    int capacity;

public:
    Queue()
    {
        rear = -1;
        front = -1;
        capacity = 1;
        arr = new int[capacity];
    }
    void resize()
    {
        capacity *= 2;
        int *newarr = new int[capacity];
        int i = 0;
        while (front <= rear)
        {
            newarr[i++] = arr[front++];
        }
        front = 0;
        rear = i - 1;
        delete arr;
        arr = newarr;
    }
    void enqueue(int val)
    {
        rear++;
        if (rear == capacity)
        {
            resize();
        }
        if (front == -1)
            front = 0;
        arr[rear] = val;
    }
    int dequeue()
    {
        if (front == -1)
            return -1;
        int temp = arr[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        return temp;
    }
    int peek()
    {
        if (front == -1)
            return -1;
        return arr[front];
    }
    bool is_empty()
    {
        return front == -1;
    }
};

class CQueue
{
public:
    int front;
    int rear;
    int capacity;
    int size;
    int *queue;

public:
    CQueue()
    {
        front = -1;
        rear = 0;
        capacity = 1;
        size = 0;
        queue = new int[capacity];
    }
    void resize()
    {
        cout << "resize called " << capacity << endl;
        capacity = capacity * 2;
        int *newQueue = new int[capacity];

        for (int i = 0; i < size; i++)
        {

            newQueue[i] = queue[(front + i) % (capacity / 2)];
        }
        front = 0;
        rear = size;
        delete queue;
        queue = newQueue;
    }
    void enqueue(int val)
    {
        if (front == -1)
        {
            front = 0;
        }
        if (size == capacity)
        {
            resize();
        }
        queue[rear] = val;
        rear = (rear + 1) % (capacity);
        size++;
    }

    int dequeue()
    {
        if (front == -1)
            return -1;
        int temp = queue[front];
        front = (front + 1) % (capacity);
        if (front == rear)
        {
            front = -1;
            rear = 0;
        }
        size--;
        return temp;
    }
    bool is_empty()
    {
        return size == 0;
    }
};

int main()
{
    CQueue q;

    cout << "Test Case 1\n";
    cout << "Expected: 1\n";
    cout << "Output  : " << q.is_empty() << "\n\n";

    cout << "Test Case 2\n";
    cout << "Expected: Underflow/Error handling\n";
    cout << "Output  : ";
    q.dequeue();
    cout << "\n\n";

    cout << "Test Case 3\n";
    q.enqueue(5);
    cout << "Expected: 0 5 1\n";
    cout << "Output  : ";
    cout << q.is_empty() << " ";
    cout << q.dequeue() << " ";
    cout << q.is_empty() << "\n\n";

    cout << "Test Case 4 (FIFO Property)\n";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Expected: 1 2 3\n";
    cout << "Output  : ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << "\n\n";

    cout << "Test Case 5 (Circular Behaviour)\n";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.enqueue(5);
    q.enqueue(6);

    cout << "Expected: 3 4 5 6\n";
    cout << "Output  : ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << "\n\n";

    cout << "Test Case 6 (Dynamic Resize)\n";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Expected: 1 2 3 4 5\n";
    cout << "Output  : ";
    for (int i = 0; i < 5; i++)
    {
        cout << q.dequeue() << " ";
    }
    cout << "\n\n";

    cout << "Test Case 7 (Resize After Wrap Around)\n";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.dequeue();
    q.dequeue();

    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    cout << "Expected: 3 4 5 6 7\n";
    cout << "Output  : ";
    for (int i = 0; i < 5; i++)
    {
        cout << q.dequeue() << " ";
    }
    cout << "\n\n";

    cout << "Test Case 8 (Multiple Resizes)\n";
    for (int i = 1; i <= 100; i++)
    {
        q.enqueue(i);
    }

    cout << "Expected: 1 2 3 ... 100\n";
    cout << "Output  : ";
    for (int i = 1; i <= 100; i++)
    {
        cout << q.dequeue() << " ";
    }
    cout << "\n\n";

    cout << "Test Case 9 (Queue Empty Again)\n";
    for (int i = 1; i <= 50; i++)
    {
        q.enqueue(i);
    }

    cout << "Expected: 1 2 3 ... 50, is_empty = 1, dequeue = 99\n";
    cout << "Output  : ";

    for (int i = 1; i <= 50; i++)
    {
        cout << q.dequeue() << " ";
    }

    cout << "| is_empty = " << q.is_empty();

    q.enqueue(99);
    cout << " | dequeue = " << q.dequeue();
    cout << "\n\n";

    cout << "Test Case 10 (Alternating Operations)\n";

    q.enqueue(1);
    int a = q.dequeue();

    q.enqueue(2);
    int b = q.dequeue();

    q.enqueue(3);
    q.enqueue(4);
    int c = q.dequeue();

    q.enqueue(5);
    int d = q.dequeue();
    int e = q.dequeue();

    cout << "Expected: 1 2 3 4 5 and is_empty = 1\n";
    cout << "Output  : ";
    cout << a << " "
         << b << " "
         << c << " "
         << d << " "
         << e
         << " | is_empty = " << q.is_empty()
         << "\n\n";

    cout << "Test Case 11 (Stress Test)\n";

    for (int i = 1; i <= 100000; i++)
    {
        q.enqueue(i);
    }

    for (int i = 1; i <= 100000; i++)
    {
        q.dequeue();
    }

    cout << "Expected: is_empty = 1\n";
    cout << "Output  : is_empty = " << q.is_empty() << "\n";

    for (int i = 1; i <= 1000; i++)
    {
        q.enqueue(i);
        q.dequeue();
    }
    cout << "Expected: is_empty = 1\n";
    cout << "Output  : is_empty = " << q.is_empty() << "\n";
    return 0;
}