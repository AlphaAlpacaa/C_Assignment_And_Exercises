#include <stdio.h>


double FindMaximum(double array, int length);

double FindMinimum(double array, int length);

int max, min;
int main(){
	int array[9] = {10,23,13,4,52,6,87,8,1};
	int length = 9;
	printf("Max=%f\tMin=%f",FindMaximum(array, length),FindMinimum(array, length));
	return 0;
}

double FindMaximum(int array, int length){
	int array[9];
	max = array[0];
	for(int i=0;i<length;i++){
		if(max<a[i]){
			max = a[i];
		}
		
	}
	return max;
	
}

double FindMinimum(int array, int length){
	int array[9];
	min= array[0];
	for(int i=0;i<length;i++){
		if(min>a[i]){
			min = a[i];
		}
		
	}
	return min;
	
	
}


