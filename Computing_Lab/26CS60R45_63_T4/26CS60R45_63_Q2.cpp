#include <iostream>
using namespace std;

class stack{
    public:
        char *arr;
        int top;
        int size;
    stack(){
        arr = new char[1000];
        top = -1;
        size = 0;
    }

    void push(char ch){
        arr[++top] = ch;
        size++;
    }
    void pop(){
        if (size > 0){
            top--;
            size--;
        }
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
// !st.is_empty() &&

int main(){
    string str;
    cin>>str;
    int max = 0;
    int count = 0;
    stack st;
    int length = 0;
    
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '('){
            // length++;
            st.push('(');
        }
        else if(!st.is_empty() && str[i] == ')' && st.get_top() == '(' ){
            st.pop();
            length += 2;
        }else{
            
            // cout<<length<<count<<endl;
            length = 0;
        }
        if(length > max){
            max = length;
                // cout<<"max :"<<max<<endl;
                count = 1;
        }
        else if(length == max){
                count++;
        }
    }
    // if(length > max) max = length;
    if(max == 0){
    cout<<max<<" "<<1<<endl;

    }
    else
    cout<<max<<" "<<count<<endl;

    return 0;
}