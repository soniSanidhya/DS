#include <iostream>
using namespace std;

class stack{
    public:
        int *arr;
        int top;
        int size;
        int capacity;
    stack(){
        capacity = 2;
        arr = new int[capacity];
        top = -1;
        size = 0;
    }
    void resize(){
        capacity *= 2;
        int *newarr = new int[capacity];
        for(int i = 0; i <= top ; i++){
            newarr[i] == arr[i];
        }
        delete arr;
        arr = newarr;
    }
    void push(int ch){
        if(capacity == size){
            resize();
        }
        arr[++top] = ch;
        size++;
    }
    int pop(){
        if (size > 0){
            size--;
            return arr[top--];
        }
        return -1;
    }
    int get_top(){
        
        if(size == 0){
            return 0;
            cout<<"size 0";
        }
        return arr[top];
    }
    bool is_empty(){
        return size == 0;
}
};


class char_stack{
    public:
        char *arr;
        int top;
        int size;
        int capacity;
    char_stack(){
        capacity = 2;
        arr = new char[capacity];
        top = -1;
        size = 0;
    }
    void resize(){
        capacity *= 2;
        char *newarr = new char[capacity];
        for(int i = 0; i <= top ; i++){
            newarr[i] == arr[i];
        }
        delete arr;
        arr = newarr;
    }
    void push(char ch){
        if(capacity == size){
            resize();
        }
        arr[++top] = ch;
        size++;
    }
    char pop(){
        if (size > 0){
            size--;
            return arr[top--];
        }
        return 0;
    }
    char get_top(){
        
        if(size == 0){
            return 0;
            cout<<"size 0";
        }
        return arr[top];
    }
    bool is_empty(){
        return size == 0;
}
};


int priority(char ch){
    if(ch == '('){
        return 0;
    }
    else if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    else return 0;
}

int operation(char ch , int y , int x){
    switch(ch){
        case '+' : return x+y;
        case '-' : return x-y;
        case '*' : return x*y;
        case '/' : return x/y;
        default : return 0;
    }
    return 0;

}

int stringtonum(string str){
    int num = 0;
    for(int i = 0 ; i  < str.length() ; i++){
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

int main(){

    string str;
    cin>>str;
    stack operand;
    char_stack operat;
    string num = "";
    for(int i = 0 ; i < str.length() ; i++){
        while(str[i] >= '0' && str[i] <= '9'){
            num = num+str[i];
            cout<<str[i]<<endl;
            i++;
        }
        
        if(num !="")
        {int number = stringtonum(num);
        cout<<"number: "<<number<<endl;
        operand.push(number);
        num = "";}
        if(!(str[i] >= '0' && str[i] <= '9')){
            
            cout<<str[i]<<endl;
            if(str[i] == '('){
                operat.push('(');
            }
            else if(str[i] == ')'){
                cout<<"poping\n";
                while(operat.get_top() == '('){
                    char op = operat.pop();
                    int x = operand.pop();
                    int y = operand.pop();
                    cout<<y<<op<<x;
                    int temp = operation(op , x , y);
                    cout<<"temp: "<<temp<<endl;
                    operand.push(temp);
                }
                operat.pop();
            }
            else if(priority(str[i]) > priority((char)operat.get_top())){
                operat.push(str[i]);
            }
            else{
                 while(!operat.is_empty() && priority(str[i]) < priority((char)operat.get_top())){
                    char op = operat.pop();
                    int x = operand.pop();
                    int y = operand.pop();
                    cout<<y<<op<<x;
                    int temp = operation(op , x , y);
                    cout<<"temp: "<<temp<<endl;
                    operand.push(temp);
                }
            }
        }
    }
     while(!operat.is_empty()){
                    char op = operat.pop();
                     int x = operand.pop();
                    int y = operand.pop();
                    cout<<y<<op<<x;
                    int temp = operation(op , x , y);
                    cout<<"temp: "<<temp<<endl;
                    operand.push(temp);
     }
    cout<<operand.pop();
    return 0;
}

// 2*(5+5*2)/3+(6/2+8)