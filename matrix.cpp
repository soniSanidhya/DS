#include <iostream>
using namespace std;

int* matrixMultiplication(int **arr1 , int **arr2 ,int m , int n){
	
	int arr[m][n];
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++ )
			arr[i][j] = 0;
	}
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < n ; k++){
				arr[i][j] = arr[i][j] + arr1[i][k]*arr2[k][j];
			}
		}
	}
	
	return arr;
}

int main(){

	int arr1[]={{1,2,3},{7,8,9},{10,11,12}};
	int arr2[]={{4,5,6},{7,8,9},{1,2,3}};
	
	int **p = matrixMultiplication(arr1, arr2 , 3,3);
	
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++ )
		{
				cout<<p[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	
	return 0;
}
