#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14

double NewtonRaphson(double f(double x), double errTol, double xInit);
double f(double x);
double x,errTol, xInit,j;
int main(){
	j=x*pi / 180;
	
	printf("enter tolerance error and initial point\n");
	scanf("%3lf %3lf",&errTol,&xInit);
	NewtonRaphson(f,errTol,xInit);
}
double f(double x){
	return (pow(x,2)*abs(sin(sqrt(x))))-10;
}
double NewtonRaphson(double f(double x), double errTol, double xInit){
	double x, x0, x1, fx0, fx1, tfx0, tfx1, a;
	double h=0.001;
	tfx0=(f(x+h)-f(x))/(h);
	a=f(x)/tfx0;
	x1=x0-a;
	printf("root is %3lf\n",x1);
	
	return x1;
}
