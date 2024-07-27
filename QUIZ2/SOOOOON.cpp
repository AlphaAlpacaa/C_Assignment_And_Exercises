// Burak ALTUNSU-040190507-ITU-EEF-KOM
// Newton-Raphson Calculator
// In DEV-C, function is given at description; doesn't work.
// That's why, I define new function for DEV-C.
// If you wish, you can use another function

// We define necessary libraries
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//definition of the function f(x)
double fx(double x)
{
	return pow(x,2)*fabs(sin(sqrt(x))) - 10; // This is the main function
	//return 2 * x * x * x - 5 * x * x - 9 * x -53 ; // Return the function
}
// We define calculation function
void NewtonRaphson(double (*fx)(double), double errTol, double xInit)
{
	int i = 1; // We counts number of iterations
	double xc = xInit; // New xc is equal to xInit
	double xk = xInit; // New xk is equal to xInit
	double h = 0.00001; // For derivative change value

	while (1)
	{
		xc = xk; // We are equalize xc and xk
		double fxprime = (fx(xc + h) - fx(xc)) / h; // Return the derivative 
		xk = xc - fx(xc) / fxprime; // We write Newton-Raphson formulas 
		i++; // Every iterations, we increase iterations number
		if ((fabs(xk-xc)) > errTol) // Compare operations 
		{
			break;
		}
	}
	printf("One root is %.4lf obtained at %dth iteration", xk, i); // We print root and iteration number when we find
}

int main()
{
	double xInit; // We define xInit
	double  errTol ; // We define error tolerance
	printf("Welcome to the Newton-Raphson Calculator");
	printf("\nEnter the initial guess xInit: "); // We take xInit from User
	scanf("%lf", &xInit);
	printf("Enter the initial guess errTol: "); // We take errTol from User
	scanf("%lf", &errTol);
	NewtonRaphson(&fx, errTol, xInit); // We call function
}
