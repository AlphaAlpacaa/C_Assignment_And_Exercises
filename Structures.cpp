#include <stdio.h> 
struct automobile { 
   int year; 
   char make[8], model[8]; 
   int engPower; 
   float weight; 
}; 
int main() 
{    struct automobile myCar = {1982, "BMW", "3.16i", 1600, 1543.5}; 
   struct automobile *ptrCar = &myCar; 
   printf("myCar.year \t= %d\n", myCar.year); 
   printf("(*ptrCar).year \t= %d\n",(*ptrCar).year); 
   printf("ptrCar->year \t= %d\n",ptrCar->year); 
   return 0; } 
