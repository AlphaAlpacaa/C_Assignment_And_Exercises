#include "numeric.h"

double trapIntegral(double (*func)(double), double low, double high, int n)
{
	int i;
	double xk, xk_1, step, sum = 0.0;
	xk = low;
	step = (high-low)/n;
	for(i=0;i<n;i++)
	{
		xk_1 = xk+step;
		sum += (func(xk_1)+func(xk)) * step / 2.0;
		xk = xk_1;
	}
	return sum;
}
double simpsonIntegral(double (*func)(double), double low, double high, int n)
{
	int i=0;
	double x_pre, x_curr, x_after, step, sum = 0.0;
	step = (high-low) / n;
	x_pre = low;
	for(i=1;i<=(n-1)*0.5;i++)
	{
		x_pre = low + step*(i*2 - 1);
		x_curr = low + step*(i*2);
		x_after = low + step*(i*2 + 1);
		sum += (func(x_pre) + 4*func(x_curr) + func(x_after)) * step / 3.0;
	}
	return sum;
}
double forwardDerivative(double (*func)(double), double point, double step)
{
	double forward = func(point+step);
	double currPoint = func(point);
	return (forward - currPoint) / step; 
}
double backwardDerivative(double (*func)(double), double point, double step)
{
	double backward = func(point-step);
	double currPoint = func(point);
	return (currPoint - backward) / step; 
}
double centralDerivative(double (*func)(double), double point, double step)
{
	double forward = func(point+step);
	double backward = func(point-step);
	return (forward - backward) / (step*2.0); 
}

double* curveFit(double* xVals, double* yVals, int dataSize,  int n)
{
	int i, j;
	double* coeffs = malloc(sizeof(double)*(n+1));
	double* A = malloc(sizeof(double)*(n+1)*(n+1));
	double* b = malloc(sizeof(double)*(n+1));
	
	//Fill A
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n+1;j++)
		{
			*(A + i*(n+1)+j) = VectorSum(VectorPow(xVals, dataSize, i+j), dataSize);
		}
	}
	
	//Fill B
	for(i=0;i<n+1;i++)
	{
		*(b+i) = DotProduct(VectorPow(xVals, dataSize, i), yVals, dataSize);
	}
	
	coeffs = Multiply(Inverse(A, n+1), b, n+1, n+1, 1);
	free(A);
	free(b);
	
	return coeffs;

}
