#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *start;
    Node *back;
    int size;
    LinkedList()
    {
        start = nullptr;
        back = nullptr;
        size = 0;
    }
    void add_front(int val)
    {
        Node *temp = start;

        Node *n = new Node(val);
        start = n;
        if (back == nullptr)
            back = n;
        start->next = temp;
        size++;
    }
    void add_back(int val)
    {
        Node *n = new Node(val);
        if (start == nullptr)
        {
            start = n;
        }
        else
        {
            back->next = n;
        }
        back = n;
        size++;
    }
    void add_position(int pos, int val)
    {
        if (pos <= 0)
            return;
        if (pos > size + 1)
            return;
        Node *n = new Node(val);
        Node *temp = start;
        if (pos == 1)
        {
            n->next = start;
            start = n;
            if (back == nullptr)
                back = n;
        }
        else
        {
            if (start == nullptr)
                return;
            while (--pos != 1)
            {
                temp = temp->next;
            }
            if (temp == back)
            {
                back = n;
            }
            n->next = temp->next;
            temp->next = n;
        }
        size++;
    }
    void print_list()
    {
        Node *temp = this->start;
        cout << endl;
        while (temp != nullptr)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
    void delete_front()
    {
        if (start != nullptr)
        {
            Node *temp = start;
            if (temp == back)
            {
                back = nullptr;
            }
            start = start->next;
            delete temp;
            size--;
        }
    }
    void delete_end()
    {
        Node *temp = start;
        Node *temp2 = nullptr;
        if (start == nullptr)
            return;
        while (temp->next)
        {
            temp2 = temp;
            temp = temp->next;
        }

        if (temp == start)
        {
            start = nullptr;
            back = nullptr;
        }
        else
        {
            temp2->next = nullptr;
        }
        if (temp == back)
        {
            back = temp2;
        }
        size--;
        delete temp;
    }

    void delete_pos(int pos)
    {
        Node *temp = start;
        Node *temp2 = nullptr;
        if (pos < 0 || start == nullptr)
            return;
        while (--pos)
        {
            if (temp == nullptr)
            {
                return;
            }
            temp2 = temp;
            temp = temp->next;
        }
        if (temp == start)
        {
            start = nullptr;
        }
        else
        {
            temp2->next = temp->next;
        }
        if (temp == back)
        {
            back = temp2;
        }
        size--;
        delete temp;
    }

    void reverse()
    {
        if (start == nullptr || start->next == nullptr)
            return;
        Node *l = start;
        Node *m = start->next;
        Node *r = m->next;

        while (m)
        {
            m->next = l;
            l = m;
            m = r;
            if (r)
                r = r->next;
        }
        start->next = nullptr;
        start = l;
    }
};

class Queue
{
private:
    LinkedList queue;

public:
    Queue()
    {
        queue = LinkedList();
    }
    void enqueue(int val)
    {
        queue.add_back(val);
    }
    int dequeue()
    {
        int temp = queue.start->data;
        queue.delete_front();
        return temp;
    }
    bool is_empty()
    {
        return queue.start == nullptr;
    }
    int peek()
    {
        return queue.start->data;
    }
};

int main()
{
    return 0;
}