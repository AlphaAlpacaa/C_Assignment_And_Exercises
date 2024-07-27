/* Program Newton-Raphson
   Program to find a root of the equation x*x*x - 3x + 1 =0 by
   Newton-Raphson method. f(x) and its derivative fd(x) are to
   be supplies.*/
 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double NewtonRaphson (float x, float *s1, float *s2)
{
    double c = 3.14159265;
    double y = c / 180;
    double new_x;

    *s1 = x*x*(fabs(sin(sqrt(x) * y))) - 10;

    *s2 = (2*x*fabs(sin(sqrt(x) * y))) + ((pow(x,1.5)*sin(sqrt(x) * y)*cos(sqrt(x) * y)) / (2 * fabs(sin(sqrt(x) * y))));	

}
 
int main()
{
    int k=0; //counts number of iterations
    float x1,x0; //x0 is the initial guess
    float eps; //error tolerance
    float s1 = 0, s2 = 0;
    printf("\nEnter the initial guess x0 : ");
    scanf("%f",&x0);
    x1=x0;
    do
    {
        k++;
        x0=x1;
        NewtonRaphson(x0,&s1,&s2);
        x1=x0-s1/s2;
    }
    while(fabs(x1-x0)>eps);
        printf("One root is %8.5f obtained at %d th iteration\n",x1,k);
}

