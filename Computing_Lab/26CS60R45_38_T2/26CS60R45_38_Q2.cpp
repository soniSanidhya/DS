#include<iostream>
using namespace std;

bool isequal(char *a , char *b){
    for(int i = 0 ;i < 3 ; i++){
        if(a[i] != b[i]) return 0;
    }
    return 1;
}

string month(string str){
    if(str.compare("Jan") == 0){
        return "01";
    }else if(str.compare("Feb") == 0){
        return "02";
    }else if(str.compare("Mar") == 0){
        return "03";
    }else if(str.compare("Apr") == 0){
        return "04";
    }else if(str.compare("May") == 0){
        return "05";
    }else if(str.compare("Jun") == 0){
        return "06";
    }else if(str.compare("Jul") == 0){
        return "07";
    }else if(str.compare("Aug") == 0){
        return "08";
    }else if(str.compare("Sep") == 0){
        return "09";
    }else if(str.compare("Oct") == 0){
        return "10";
    }else if(str.compare("Nov") == 0){
        return "11";
    }else if(str.compare("Dec") == 0){
        return "12";
    }
    else return "";
}

void swap(string *a , string *b){
    string temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n;
    cin>>n;
    n = n +1 ;

    string dates[n];

    for(int i = 0 ;i < n ; i++){
        getline(cin ,dates[i]);
    }

    string arr[n];

    for(int i = 1; i < n ; i++){
        string temp = "";
        if(dates[i][2] == '-'){
    
            temp += dates[i].substr(7,4);
            temp += month(dates[i].substr(3,3));
            temp += dates[i].substr(0,2);
            
        }else {

            temp += dates[i].substr(8,4);
            temp += month(dates[i].substr(0,3));
            temp += dates[i].substr(4,2);
        }
        arr[i] = temp;
    }

    for(int i = 1 ; i < n-1 ; i++){
        for(int j = 0 ; j < n - i ; j++){
            string st = arr[j];
            if(st.compare(arr[j+1]) > 0){
                swap(&dates[j] , &dates[j+1]);
                swap(&arr[j] , &arr[j+1]);
            }
        }
    }

    for(int i = 1 ; i < n; i++){
        cout<<dates[i]<<endl;
    }

    return 0;
}
// 0 1 2 3 4 5 6 7 8 9 10
// 1 7 - J u l - 2 0 1 9
// 0 1 2 3 4 5 6 7 8 9 10
// 3 1 - D e c - 2 0 1 8
// 0 1 2 3 4 5 6 7 8 9 1011
// M a r   1 2 ,   2 0 1 9

// 17-Jul-2019
// 31-Dec-2018
// Mar 12, 2019
// 01-Jan-2019