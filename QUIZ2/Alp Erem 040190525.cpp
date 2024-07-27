#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fx(double x);

void NewtonRaphson(double (*fx)(double), double errTol, double xInit);

int main()
{
	double xInit, errTol; //define variables
	NewtonRaphson(&fx, 0.001, 1);
}

void NewtonRaphson(double (*fx)(double), double errTol, double xInit)
{
	int i = 1, counter=1; //define variables
	double x0 = xInit, x1 = xInit,  h = 0.00000001;
	while (counter)
	{
		x0 = x1;
		double fxprime = (fx(x0 + h) - fx(x0)) / h; //take the derivative of fx
		x1 = x0 - fx(x0) / fxprime; //newtonRaphson formula
		i++;
		if ((fabs(x1-x0)) < errTol) //compare operations 
		{
			counter=0;
		}
	}
	printf("\nOne root is %.4lf obtained at %dth iteration", x1, i);
}

double fx(double x) //define the function f(x)
{
	return pow(x,2)*fabs(sin(sqrt(x))) - 10; //function
}
