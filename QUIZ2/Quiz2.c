#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x); //declaration of the function 

void newtonRaphson(double (*f)(double), double errTol, double xInit); //dclaration of the function 

int main()
{
	double xInit, errTol; //define variables
	newtonRaphson(&f, 0.0001, 1);
}

void newtonRaphson(double (*f)(double), double errTol, double xInit) // define newtonRapson function
{
	int i = 1, counter=1; //define variables
	double x0 = xInit, x1 = xInit,  h = 0.00000001;
	while (counter)
	{
		x0 = x1;
		double fprime = (f(x0+h)-f(x0))/h; //take the derivative of fx
		x1 = x0-f(x0)/fprime; //NewtonRaphson formula
		if ((fabs(x1-x0)) < errTol) //compare operations 
		{
			counter=0;
		}
		i++;
	}
	printf("\nOne root is %.4lf obtained at %dth iteration", x1, i);
}

double f(double x) //define the function of f
{
	return pow(x,2)*fabs(sin(sqrt(x))) - 10; 
}
