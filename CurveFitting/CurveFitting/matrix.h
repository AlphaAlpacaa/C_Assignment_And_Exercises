#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef MATRIX_H
#define MATRIX_H

// Variables
typedef struct Complex {
	double Re, Im;
} complex;

// Functions
double* Add(double*, double*, int, int); //**
double* Subs(double*, double*, int, int); //**
double* Multiply(double*, double*, int, int, int); //**
double* Transpose(double*, int, int);
double Trace(double*, int);
double DotProduct(double*, double*, int); //**
double* CrossProduct(double*, double*);
double VectorSum(double*, int); //**
double* VectorPow(double*, int, int);
double* CoFactor(double*, int, int, int, int);
double Determinant(double*, int);
double* Inverse(double*, int); //**
double* GetColumn(double* matrix, int col, int rowCount,  int colCount);

double VectorMagnitude(double*, int);
void VectorNormalization(double*, int);

complex* Eigenvalues2x2(double*);
void ShowMatrix(double*, int, int); //**

#endif
