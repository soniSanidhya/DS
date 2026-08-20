#include <stdio.h>

void swap(int *a , int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permutation(int arr[] , int r , int n){
	if(r==n) return;
	for(int i = r ; i < n ; i++){
		permutation(arr , r +1 , n);
		swap(&arr[i] , &arr[r]);
		
		for(int i = 0 ; i < n ; i++){
			printf("%d\t" , arr[i] );
		}
		printf("\n");
	}
}

int main(){
////	int arr[] = {1,2 ,3};
////	permutation(arr , 0 , 3);
//int x = -5;
////int y =  -x++;
////x =  x++;
////x = x;
//x = -x++;
//
//x = -x++;
////x = -x++;
//x = -x++;
////x = -x++;
//
//printf("%d \n", x);

//int/*asd*/x=029;
//printf("%d", x);



  int n = 2;
  int j = 1;
  int i;
  for(i=1 ; i < n*n*n ; i++){
      for(i=1 ; i < n*n ; i++){
          for(i=1 ; i < n ; i++){
              j++;
               
  printf("%d", j);
          }
      }
  }
 

}
