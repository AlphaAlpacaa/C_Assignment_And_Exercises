#include <stdio.h> 
int main() 
{ 
   int i, arr[3] = { 1, 3, 5 }; 
   int *ptrArr = arr; 
   for (i = 0; i < 3; i++) 
      printf("arr[%d] = %d\n", i, *(ptrArr + i)); 
   return 0; 
}
