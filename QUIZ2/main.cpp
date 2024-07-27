#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//definition of the function f(x)
float f(float x)
{
	return x * x * abs(sin(pow(x, 0.5))) - 10;
	// return x * x - 5 * x - 6;
}

float fPrime(float x)
{
	float h = 0.00001;
	return (f(x + h) - f(x)) / h;
}

float NewtonRaphson(float errTol)
{
	int i = 0; //counts number of iterations
	float x1, x2;
	printf("\nEnter the initial guess x0: ");
	scanf("%f", &x1);
	x2 = x1;
	while (1)
	{
		x1 = x2;
		x2 = x1 - f(x1) / fPrime(x1);
		i++;
		if (f(x2) < errTol + 0)
			break;
	}
	printf("One root is %.4f obtained at %dth iteration", x2, i);
}

int main()
{
	float errTol = 0.0001; //error tolerance
	NewtonRaphson(errTol);
}
