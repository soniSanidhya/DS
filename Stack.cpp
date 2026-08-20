#include <iostream>
using namespace std;

class Vector
{
private:
    int *arr;
    int capacity;
    int size;

public:
    Vector()
    {
        capacity = 1;
        arr = new int[capacity];
        size = 0;
    }
    void resize()
    {
        capacity = capacity * 2;
        int *newarr = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            newarr[i] = arr[i];
        }
        delete arr;
        arr = newarr;
    }
    void push_back(int val)
    {
        if (capacity == size)
            resize();
        arr[size] = val;
        size++;
    }
    int operator[](int ind)
    {
        return arr[ind];
    }
};

class Stack
{

private:
    int top;
    int capacity;
    int *arr;

public:
    Stack()
    {
        top = -1;
        capacity = 1;
        arr = new int[capacity];
    }
    void resize()
    {
        capacity = capacity * 2;
        int *new_arr = new int[capacity];
        for (int i = 0; i <= top; i++)
        {
            new_arr[i] = arr[i];
        }
        delete arr;
        arr = new_arr;
    }
    void push(int val)
    {
        top++;
        if (capacity == top)
            resize();
        arr[top] = val;
    }
    int pop(){
        if(top == -1) return -1 ;
        return arr[top--];
    }
    int peek(){
        if(top == -1) return -1 ;
        return arr[top];
    }
    int size(){
        return top+1;
    }
    bool is_empty(){
        return top == -1;
    }
};
int main()
{
    cout << "========== Stack Test Cases ==========" << endl;
    
    // Test Case 1: Basic push and pop
    cout << "\nTest 1: Basic push and pop" << endl;
    Stack st1 = Stack();
    st1.push(10);
    st1.push(20);
    st1.push(30);
    cout << "Pushed: 10, 20, 30" << endl;
    cout << "Pop: " << st1.pop() << endl;  // Should be 30
    cout << "Pop: " << st1.pop() << endl;  // Should be 20
    cout << "Pop: " << st1.pop() << endl;  // Should be 10
    cout << "Size: " << st1.size() << endl;
    
    // Test Case 2: is_empty() check
    cout << "\nTest 2: is_empty() check" << endl;
    Stack st2 = Stack();
    cout << "Empty stack - is_empty(): " << (st2.is_empty() ? "true" : "false") << endl;
    st2.push(5);
    cout << "After push - is_empty(): " << (st2.is_empty() ? "true" : "false") << endl;
    st2.pop();
    cout << "After pop - is_empty(): " << (st2.is_empty() ? "true" : "false") << endl;
    
    // Test Case 3: peek() without removing
    cout << "\nTest 3: peek() without removing" << endl;
    Stack st3 = Stack();
    st3.push(100);
    st3.push(200);
    st3.push(300);
    cout << "Peek: " << st3.peek() << " (top element)" << endl;
    cout << "Peek again: " << st3.peek() << " (should be same)" << endl;
    cout << "Size: " << st3.size() << " (should be 3)" << endl;
    
    // Test Case 4: LIFO (Last In First Out) property
    cout << "\nTest 4: LIFO (Last In First Out) property" << endl;
    Stack st4 = Stack();
    st4.push(1);
    st4.push(2);
    st4.push(3);
    st4.push(4);
    st4.push(5);
    cout << "Pushed: 1, 2, 3, 4, 5" << endl;
    cout << "Popping in order: ";
    while (!st4.is_empty()) {
        cout << st4.pop() << " ";
    }
    cout << endl;
    
    // Test Case 5: size() tracking
    cout << "\nTest 5: size() tracking" << endl;
    Stack st5 = Stack();
    cout << "Initial size: " << st5.size() << endl;
    st5.push(10);
    cout << "After 1 push: " << st5.size() << endl;
    st5.push(20);
    st5.push(30);
    cout << "After 3 total pushes: " << st5.size() << endl;
    st5.pop();
    cout << "After 1 pop: " << st5.size() << endl;
    st5.pop();
    st5.pop();
    cout << "After 3 total pops: " << st5.size() << endl;
    
    // Test Case 6: pop on empty stack
    cout << "\nTest 6: pop on empty stack" << endl;
    Stack st6 = Stack();
    cout << "Pop on empty stack: " << st6.pop() << " (should be -1)" << endl;
    
    // Test Case 7: peek on empty stack
    cout << "\nTest 7: peek on empty stack" << endl;
    Stack st7 = Stack();
    cout << "Peek on empty stack: " << st7.peek() << " (should be -1)" << endl;
    
    // Test Case 8: Multiple push and pop cycles
    cout << "\nTest 8: Multiple push and pop cycles" << endl;
    Stack st8 = Stack();
    cout << "Cycle 1 - Push 50, 60: ";
    st8.push(50);
    st8.push(60);
    cout << "Pop: " << st8.pop() << endl;
    cout << "Cycle 2 - Push 70, 80, 90: ";
    st8.push(70);
    st8.push(80);
    st8.push(90);
    cout << "Pop: " << st8.pop() << ", " << st8.pop() << endl;
    
    // Test Case 9: Capacity resizing (pushing many elements)
    cout << "\nTest 9: Capacity resizing (pushing many elements)" << endl;
    Stack st9 = Stack();
    for (int i = 1; i <= 20; i++) {
        st9.push(i * 10);
    }
    cout << "Pushed 20 elements (should handle resizing)" << endl;
    cout << "Size: " << st9.size() << endl;
    cout << "Peek (top): " << st9.peek() << endl;
    cout << "Pop last 3: " << st9.pop() << ", " << st9.pop() << ", " << st9.pop() << endl;
    cout << "Size after 3 pops: " << st9.size() << endl;
    
    // Test Case 10: Single element operations
    cout << "\nTest 10: Single element operations" << endl;
    Stack st10 = Stack();
    st10.push(999);
    cout << "Pushed 999" << endl;
    cout << "Peek: " << st10.peek() << endl;
    cout << "Size: " << st10.size() << endl;
    cout << "Pop: " << st10.pop() << endl;
    cout << "Size after pop: " << st10.size() << endl;
    cout << "is_empty(): " << (st10.is_empty() ? "true" : "false") << endl;
    
    cout << "\n========== All Tests Completed ==========" << endl;
    return 0;
}
