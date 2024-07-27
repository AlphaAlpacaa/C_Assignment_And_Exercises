
/* Program Newton-Raphson
   Program to find a root of the equation x*x*x - 3x + 1 =0 by
   Newton-Raphson method. f(x) and its derivative fd(x) are to
   be supplies.*/
 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
 
int main()
{
 int k=0; //counts number of iterations
 float x1,x0; //x0 is the initial guess
 float eps=0.0001; //error tolerance
 float f(float x);
 float fd(float x);
 printf("\nEnter the initial guess x0 : ");
 scanf("%f",&x0);
 x1=x0;
 do
 {
 	k++;
 	x0=x1;
 	x1=x0-f(x0)/fd(x0);
 }
 while(fabs(x1-x0)>eps);
 	printf("One root is %8.5f obtained at %d th iteration\n",x1,k);
}	
 
//definition of the function f(x)
float f(float x)
{
 return(x*x*x-3*x+1);
}
 
//definition of the function fd(x)
float fd(float x)
{
 return(3*x*x-3);
}
