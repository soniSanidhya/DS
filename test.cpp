#include<bits/stdc++.h>
using namespace std;

void  subset(int i , vector<vector<int>> &subsets , vector<int> temp , vector<int> vec){
    if(i == vec.size()){
        subsets.push_back(temp);
        return;
    }
    temp.push_back(vec[i]);
    subset(i+1, subsets , temp , vec );
    temp.pop_back();
    subset(i+1, subsets , temp , vec );
}

int main(){
 vector<vector<int>> subsets;
 vector<int> temp;
 vector<int> vec = {1,2,3};
 subset(0 , subsets , temp , vec);
 for(auto a : subsets){
    for(auto b : a){
        cout<<b<<"\t";
    }
    cout<<endl;
 }
}