#include <stdio.h>
#include <math.h>
#define EPS 0.001
double fx(double);
double Midpoint(double (*f)(double), double xL, double xU);
int main() {
printf("Solution is x=%.4lf\n",Midpoint(fx,0,4));
return 0; }
double Midpoint(double (*f)(double), double xL, double xU) {
      double xm = (xU+xL)/2;
      if(f(xL)*f(xU)>0)
      {
printf("There is no root in (%.2lf,%.2lf)\n",xL,xU);
return 0; }
      while(fabs(f(xm))>EPS)
      {
            if(f(xL)*f(xm)<0)
                  xU = xm;
            else if(f(xL)*f(xm)>0)
                  xL = xm;
else
break;
            xm = (xL+xU)/2;
      }
return xm;
}
double fx(double x)
{
      return (x*x*(abs(sin(pow(x,0.5))))-10);
}
