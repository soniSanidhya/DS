#include <iostream>
#include<vector>
using namespace std;

void perm(vector<string>& s ,string curr, string str, int i , int n){
    if(i == n){
        s.push_back(curr);
        return;
    }

    

    perm(s , curr + str[i],str , i+1,n);  // take case
    perm(s , curr ,str, i+1 ,n);      // not take case
}

int main(){
	vector<string> vec;
	perm(vec ,"", "abc" ,0, 3);
	for(int i = 0 ; i < vec.size() ; i++){
		cout<<vec[i]<<endl;
	}
	return 0;
}
