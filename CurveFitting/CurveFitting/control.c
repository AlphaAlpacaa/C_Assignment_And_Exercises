#include "control.h"

double* systemId(double* xVals, double* yVals, int dataSize, int sysDeg)
{
	int i, j;
	//y[k] = a0*u[k] + a1*u[k-1] + a2*y[k-1] + a3*y[k-2]; 
	double* regressors = malloc(sizeof(double)*dataSize*sysDeg*2);
	for(i=0;i<dataSize;i++)
	{
		//Input regressors
		for(j=0;j<sysDeg;j++)
		{
			int index = i-j;
			if(index < 0)
			{
				index = 0;
			}
			*(regressors + i*(sysDeg*2) + j) = xVals[index];
		}
		
		//Outputs
		for(j=0;j<sysDeg;j++)
		{
			int index = i-j-1;
			if(index < 0)
			{
				index = 0;
			}
			*(regressors + i*(sysDeg*2) + j+sysDeg) = yVals[index];
			//regressors[i][j+sysDeg] = xVals[index];
		}
		printf("Regressor: %lf %lf %lf %lf\n", *(regressors + i*(sysDeg*2)), *(regressors + i*(sysDeg*2)+1), *(regressors + i*(sysDeg*2)+2), *(regressors + i*(sysDeg*2)+3));
		 
	}
	double* A = malloc(sizeof(double) * (sysDeg*2) * (sysDeg*2));
	double* b = malloc(sizeof(double) * (sysDeg) * 2);
	double* coeffs = malloc(sizeof(double) * (sysDeg) * 2);
	for(i=0;i<sysDeg*2;i++)
	{
		for(j=0;j<sysDeg*2;j++)
		{
			double* col_1 = GetColumn((double*)regressors, i, dataSize, sysDeg*2);
			double* col_2 = GetColumn((double*)regressors, j, dataSize, sysDeg*2);
			*(A + i*(sysDeg*2) + j) = DotProduct(col_1, col_2, dataSize);
			printf("Test %lf\n", DotProduct(col_1, col_2, dataSize));
		}
		
	}
	
	for(i=0;i<sysDeg*2;i++)
	{
		double* col = GetColumn(regressors, i, dataSize, sysDeg*2);
		b[i] = DotProduct(yVals, col, dataSize);
	}
	
	coeffs = Multiply(Inverse(A, sysDeg*2), b, sysDeg*2, sysDeg*2, 1);
	free(A);
	free(b);
	
	return coeffs;
}
