#include<bits/stdc++.h>
using namespace std;

void set_unsafe(vector<vector<int>> &grid , vector<vector<int>> guards){
    int r = grid.size();
    int c = grid[0].size();
    for(auto guard : guards){
        for(int i = guard[0] - guard[2] ; i <= guard[0] + guard[2] ; i++){
            for(int j = guard[1] - guard[2] ; j <= guard[1] + guard[2] ; j++){
                if(i >= 0 && i < r && j >= 0 && j < c){
                    grid[i][j] = 1;
                }
            }
        }
    }
}

int find_rout(vector<vector<int>> &grid , int i , int j , int path){
    int r = grid.size();
    int c = grid[0].size();
   
    int min_ = INT_MAX , t = 0;
    if(i >= 0 && i < r && j >= 0 && j < c){

        if(grid[i][j] == -2) return path;
        if(grid[i][j] == 1) return INT_MAX;
         cout<<i<<" "<<j<<" "<<path<<endl;
        grid[i][j] = 1;
        t = find_rout(grid , i-1 , j-1 , path + 1);
        min_ = min(min_ , t);
        t = find_rout(grid , i-1 , j , path + 1);
        min_ = min(min_ , t);
        t = find_rout(grid , i-1 , j+1 ,path + 1);
        min_ = min(min_ , t);        
        t = find_rout(grid , i , j-1,path + 1);
        min_ = min(min_ , t);        
        t = find_rout(grid , i , j+1,path + 1);
        min_ = min(min_ , t);        
        t = find_rout(grid , i+1 , j-1,path + 1);
        min_ = min(min_ , t);        
        t = find_rout(grid , i+1 , j,path + 1);
        min_ = min(min_ , t);        
        t = find_rout(grid , i+1 , j+1,path + 1);
        min_ = min(min_ , t);
        grid[i][j] = 0;
    }
    return min_;
}

int main(){

    int h ,w ,n ,k ,sr ,sc;
    cin>> h >> w >> n >> k;
    cin>> sr >> sc;
    vector<vector<int>> grid(h , vector<int>(w , 0));
    vector<vector<int>> guards(n,vector<int>(3));
    for(int i = 0 ; i < k ; i++){
        int e1 , e2;
        cin>>e1>>e2;
        grid[e1][e2] = -2;
    }
    for(int i = 0 ; i < n ; i++){
        cin>>guards[i][0]>>guards[i][1]>>guards[i][2];
    }
    set_unsafe(grid , guards);
    int res = find_rout(grid , sr , sc , 0);
    if(res == INT_MAX){
        cout<<"NO";
    }
    else{
        cout<<"YES "<<res;
    }
    return 0;
}

// 5 5 1 2
// 2 0
// 0 4
// 4 4
// 2 2 1

// 5 5 3 1
// 2 0
// 2 4
// 0 2 1
// 2 2 1
// 4 2 1