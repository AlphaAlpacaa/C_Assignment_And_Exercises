#ifndef NUMERIC_H
#define NUMERIC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


double trapIntegral(double (*func)(double), double low, double high, int n);
double simpsonIntegral(double (*func)(double), double low, double high, int n);
double forwardDerivative(double (*func)(double), double point, double step);
double backwardDerivative(double (*func)(double), double point, double step);
double centralDerivative(double (*func)(double), double point, double step);

//Curve Fitting
double* curveFit(double* xVals, double* yVals, int dataSize, int n);

#endif NUMERIC_H
