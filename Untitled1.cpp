#include <stdio.h> 

int main() 
{ 
   int n, result=1;
   printf("Enter n\n");
   scanf("%d", &n);
   if (n < 30)
   {
   		while (n > 1) 
	   {
	   result *= n--;
	   }
   }
   		
   			
	printf("%d",result);
   
   
   
   
   	
   
   
   return 0; } 
