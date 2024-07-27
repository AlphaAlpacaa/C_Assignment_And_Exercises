#include<stdio.h>
#include<math.h>

double test_f(double x);
double Secant(double (*f)(double),double eps,double *xInitials);

int main(){
	double xInitials[2]={1,2};
	double eps=0.001;
	printf("%.5f", Secant(test_f,eps,xInitials));
	return 0;
}

double test_f(double x){
	return pow(x,2)*fabs(sin(sqrt(x)))-10;
}

double Secant(double (*f)(double),double eps,double *xInitials){
	double xk,xk_1,xk_temp;
	xk=xInitials[0];
	xk_1=xInitials[1];
	while(fabs(xk_1-xk)>eps){
		xk_temp=xk-((f(xk)*(xk-xk_1))/(f(xk)-f(xk_1)));
		xk_1=xk;
		xk=xk_temp;	
	}
	return xk;
}

