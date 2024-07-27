#include <stdio.h>

void swapHalves(int *arr, int size){
	float a = size/2;
	if(a%2==0){
		int temp;
		for(int i=0;i<a;i++){
			temp=*arr+i+a;
			*arr+i=*arr+i+a;
			*arr+i=temp;
		}		
	}
	else{
		int a= size/2-1
		int temp;
		for(int i=0;i<a;i++){
			temp=*arr+i+a;
			*arr+i=*arr+i+a;
			*arr+i=temp;
		}		
	}	
}
