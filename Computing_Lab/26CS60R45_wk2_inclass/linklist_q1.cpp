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
};

int main()
{
    int n;
    cin >> n;
    linkedlist ll;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int x;
        if (str.compare("INSERT_HEAD") == 0)
        {
            cin >> x;
            ll.insert_head(x);
        }
        else if (str.compare("INSERT_TAIL") == 0)
        {
            cin >> x;
            ll.insert_tail(x);
        }
        else if (str.compare("DELETE") == 0)
        {
            cin >> x;
            ll.delete_node(x);
        }
        else if (str.compare("PRINT") == 0)
        {
            ll.print_list();
        }
        else
        {
            cout << "\nWRONG INPUT\n";
            i--;
        }
    }
}

// 26CS60R45_WK2_inclass