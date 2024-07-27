#include<stdio.h>


int findMaximum(int *A, int size){
	int i,max;
	max = *(A);
	for(i=0;i<size;i++){
		if(*(A+i)>max){
			max=*(A+i);
		}
	}
	return max;	
}
int findMinimum(int *A, int size){
	int i,min;
	min = *(A);
	for(i=0;i<size;i++){
		if(*(A+i)<min){
			min=*(A+i);
		}
	}
	return min;		
}
int main(){
	int A[10]={1,2,0,-5,5,8,102,15,20,200};
	printf("Maximum value: %d, Minimum value: %d",findMaximum(A,10),findMinimum(A,10));

	return 0;	
}

