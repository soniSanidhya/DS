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

    node *get_tail()
    {
        return tail;
    }

    node *get_head()
    {
        return head;
    }

    int get_size()
    {
        return size;
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
    void merge_list(linkedlist *ll)
    {
        node *t1 = head;
        node *t2 = ll->head;
        node *prev = nullptr;
        // cout<<t1->data;
        // cout<<t2;
        while (t1 != nullptr && t2 != nullptr)
        {

            if (t1->data <= t2->data)
            {
                if (prev == nullptr)
                {
                    // cout<<"t1 has smaller head"<<t1->data;
                    prev = t1;
                }
                else
                {
                    prev->next = t1;
                    prev = prev->next;
                }
                t1 = t1->next;
            }
            else
            {
                if (prev == nullptr)
                {
                    // cout<<"t2 has smaller head"<<t1->data;
                    head = ll->get_head();
                    prev = t2;
                }
                else
                {
                    prev->next = t2;
                    prev = prev->next;
                }
                t2 = t2->next;
            }
        }

        if (t1)
        {
            if (prev == nullptr)
                head = t1;
            else
                prev->next = t1;
        }
        if (t2)
        {
            if (prev == nullptr)
                head = t2;
            else
                prev->next = t2;
            tail = ll->get_tail();
        }
        size += ll->get_size();
    }
};

int main()
{
    int n1, n2, x;
    cin >> n1;
    linkedlist ll1, ll2;
    while (n1--)
    {
        cin >> x;
        ll1.insert_tail(x);
    }
    cin >> n2;

    while (n2--)
    {
        cin >> x;
        ll2.insert_tail(x);
    }
    ll1.merge_list(&ll2);
    ll1.print_list();
}

// 26CS60R45_WK2_home