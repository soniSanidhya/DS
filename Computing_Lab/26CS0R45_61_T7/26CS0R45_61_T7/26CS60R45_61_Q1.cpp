#include<bits/stdc++.h>
using namespace std;


string get_path(string str){
    string res = "";
    for(char c : str){
        switch(c){
            case 'S' :
                res = res+"N";
                break;
            case 'N' :
                res = res+"S";
                break;
            case 'W' :
                res = res+"E";
                break;
            case 'E' :
                res = res +"W";
                break;
        }
    }
    return res;
}



string solve(vector<char> str){
    map<pair<int,int> , string> m;
    int i = 0 , j = 0;
    for(char c: str){
      if(c == 'N'){
        if(m[{i-1,j}].length() != 0){
            if(m[{i-1,j}].length() >  m[{i,j}].length()+1){
                  m[{i-1 , j}] = "N" + m[{i,j}];
            }
        }else{
            m[{i-1 , j}] = "N" + m[{i,j}];
        }
        i = i-1;
      }
      else if(c == 'S'){
        if(m[{i+1,j}].length() != 0){
            if(m[{i+1,j}].length() >  m[{i,j}].length()+1){
                  m[{i+1 , j}] = "S" + m[{i,j}];
            }
        }else{
            m[{i+1 , j}] = "S" + m[{i,j}];
        }
        i = i+1;
      } else if(c == 'W'){
        if(m[{i,j-1}].length() != 0){
            if(m[{i,j-1}].length() >  m[{i,j}].length()+1){
                  m[{i , j-1}] = "W" + m[{i,j}];
            }
        }else{
            m[{i , j-1}] = "W" + m[{i,j}];
        }
        j = j-1;
      }
      else if(c == 'E'){
        if(m[{i,j+1}].length() != 0){
            if(m[{i,j+1}].length() >  m[{i,j}].length()+1){
                  m[{i , j+1}] = "E" + m[{i,j}];
            }
        }else{
            m[{i , j+1}] = "E" + m[{i,j}];
        }
        j = j+1;  
      }
    }
    if(i == 0 && j == 0) return "";
    return get_path(m[{i,j}]);
}
// WNWNESWWNWSWN
// SENESEESE

int main(){

    int n;
    cin>>n;
    vector<char> str(n);
    for(int i = 0 ; i < n ; i++){
        cin>>str[i];
    }
    string res = solve(str);
    for(char c : res){
        cout<<c<<" ";
    }
    return 0;
}

// WNWNESWWNWSWN