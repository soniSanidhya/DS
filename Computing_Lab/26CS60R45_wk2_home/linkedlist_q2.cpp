#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class linkedlist
{

private:
    int size;
    node *head;
    node *tail;

public:
    linkedlist()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    void insert_head(int val)
    {
        node *n = new node(val);
        if (tail == nullptr)
        {
            tail = n;
        }
        n->next = head;
        head = n;
        size++;
    }
    void insert_tail(int val)
    {
        node *n = new node(val);
        if (head == nullptr)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        size++;
    }

    void delete_node(int target)
    {
        node *temp = head;

        node *prev = nullptr;
        while (temp != nullptr && temp->data != target)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp && temp == head)
        {
            head = head->next;
        }
        else if (temp && temp == tail)
        {
            prev->next = nullptr;
            tail = prev;
        }
        else if (temp != nullptr)
        {
            prev->next = temp->next;
        }

        if (temp)
            size--;
            delete temp;
    }
    void print_list()
    {
        node *temp = head;
        if (temp == nullptr)
        {
            cout << "EMPTY\n";
        }
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    node *reverse_helper(node *n)
    {
        if (n == tail)
        {
            head->next = nullptr;
            tail = head;
            head = n;
            return n;
        };
        node *t = reverse_helper(n->next);
        t->next = n;
        return n;
    }
    bool is_empty()
    {
        return size == 0;
    }
    void reverse()
    {
        if (!is_empty())
            reverse_helper(head);
    }
};

int main()
{
    int n, x;
    cin >> n;
    linkedlist ll;
    while(n--)
    {
        cin >> x;
        ll.insert_tail(x);
    }
    ll.reverse();
    ll.print_list();
}

// 26CS60R45_WK2_home