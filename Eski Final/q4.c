#include<stdio.h>
#include<math.h>

double fx(double x){
	return pow(x,2)*fabs(sin(sqrt(x)))-10;
}

double Secant(double (*f)(double),double eps,double *xInitials){
	double xk1,xk,xk_1;
	xk=xInitials[0];
	xk_1=xInitials[1];
	while(fabs(xk-xk_1)>eps){
		xk1=xk-((f(xk)*(xk-xk_1))/(f(xk)-f(xk_1)));
		xk_1=xk;
		xk=xk1;
		
	}
	return xk;
}

int main(){
	double xInitials[2]={1,2};
	double eps=0.001;
	printf("%lf", Secant(fx,eps,xInitials));
	
	return 0;
}
