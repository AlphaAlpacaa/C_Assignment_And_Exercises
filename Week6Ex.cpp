#include<stdio.h>

int main(){
	int num = 42;
	int *p_num = &num;
	printf("%p\n", p_num);
	printf("%p\n", &num);
	printf("%d\n", *p_num);
	
	int** p_p_num = &p_num;
	printf("%p\n", p_p_num);
	printf("%p\n", *p_p_num);
	
	float flt_num = 42.42;
	void* void_ptr = &flt_num;
	printf("%.2f\n", *(float*)void_ptr);
	
	int arr[5] = {505, 515, 123, 34, 454};		
	int* ptr_arr = arr;
	for(int i=0;i<5;i++){
		printf("%d\n", arr[i]);

	}
			
}


