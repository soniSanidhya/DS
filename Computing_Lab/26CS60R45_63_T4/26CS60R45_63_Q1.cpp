#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = nullptr;
    }
};

node* helper(node *head , node *tail){
    node *p = head;
    node *c = head ->next;
    p->next =nullptr;
    node *n;
    if(c != nullptr){
        n = c->next;
    }

    while(p != tail){
        c->next = p;
        p = c;
        c = n;
        if(n != nullptr)
        n = n->next;
    }
    return p;
}

node* reverse(node *head , int k){
    node *temp = head;
    node *dummy = new node(0);
    node *head2 = dummy; 
    while(temp != nullptr){
        node * tail = temp;
        node *temp2 = nullptr;

        for(int i = 1 ; i < k && tail->next != nullptr ; i++){
            tail = tail->next;
        }
        if(tail)
        temp2 = tail->next;
        dummy->next = helper(temp , tail);
        dummy = temp;
        temp = temp2;

    }
    return head2->next;
}


int main(){
    int n , k;
    cin>>n>>k;
    node *temp = new node(-1);
    node *head = temp;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin>>x;
        node *n = new node(x);
        temp->next = n;
        temp = temp->next;
    }
    head = head->next;
    temp = head;

    temp = reverse(head , k);


    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    return 0;

}