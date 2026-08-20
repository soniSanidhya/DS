#include<bits/stdc++.h>
using namespace std;



int longest_palindrome(string str1 , string str2 , int i , int j , vector<vector<int>> &dp ){
    if(i == str1.length() || j == str2.length()) return 0;
    if(dp[i][j] != -1) return dp[i][j]; 
    if(str1[i] == str2[j]){

        return dp[i][j] = longest_palindrome(str1 , str2 , i+1 , j+1 , dp) +1;
    }
    else{
        return dp[i][j] = max(longest_palindrome(str1 , str2 , i +1 , j , dp), longest_palindrome(str1 , str2 , i , j+1 , dp));
    }
}

int main(){
    string str1 = "bbab";
    string str2 = str1;
    vector<vector<int>> dp(str1.length() , vector<int>(str2.length() , -1));
    reverse(str2.begin() , str2.end());
    cout<<longest_palindrome(str1 , str2 , 0 ,0 , dp);
}