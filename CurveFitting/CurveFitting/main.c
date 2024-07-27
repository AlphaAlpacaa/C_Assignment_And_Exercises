#include "matrix.h"
#include "numeric.h"
#include "control.h"
#include <stdio.h>
#include <stdlib.h>

int loadData(const char* filename, double** xVals, double** yVals);
int saveData(const char* filename, double* xVals, double* yVals, int dataSize);
int main()
{

	double* xVals = NULL;
	double* yVals = NULL;
	int dataSize = loadData("./system.txt", &xVals, &yVals);
	
	if(yVals == NULL)
	{
		printf("NBull");
	}

	
	//Fit curve
	int n = 1; //Linear regression
	double* coeffs = curveFit(xVals, yVals, dataSize, n);
	printf("Coeffs: a0 %f  a1 %f\n", coeffs[0], coeffs[1]);
	
	//Sys identification
	double* sysCoeffs = systemId(xVals, yVals, dataSize, 2);
	if(sysCoeffs == NULL)
	{
		printf("Null");
	}
	printf("System Coeffs: a0: %lf ", sysCoeffs[1]);
}

int loadData(const char* filename, double** xVals, double** yVals)
{
	//Returns the read datasize. -1 if couldn't read
	FILE* dataFile;
	dataFile = fopen(filename, "r");  //Open for reading
	if(dataFile == NULL)
	{
		return -1;
	}
	
	//First line is the data amount
	int dataSize;
	char lineBuffer[20];
	*(xVals) = malloc(sizeof(double)*dataSize);
	*(yVals) = malloc(sizeof(double)*dataSize);
	fgets(lineBuffer, 20, dataFile);
	sscanf(lineBuffer, "%d", &dataSize);
	for(int i=0;i<dataSize+1;i++)
	{
		if(feof(dataFile))
		{
			printf("Yo");
			return -1;
		}
		double xVal, yVal;
		
		fgets(lineBuffer, 20, dataFile);
		int check = sscanf(lineBuffer, "%lf %lf", &xVal, &yVal);
		(*(xVals))[i] = xVal;
		(*(yVals))[i] = yVal;

	}
	fclose(dataFile);
	return dataSize;
}

int saveData(const char* filename, double* xVals, double* yVals, int dataSize)
{
	//Returns 1 if correctly saves
	FILE* dataFile;
	dataFile = fopen(filename, "w");
	if(dataFile == NULL)
	{
		return 0;
	}
	
	fprintf(dataFile, "%d\n", dataSize);
	for(int i=0;i<dataSize;i++)
	{
		fprintf(dataFile,"%.2f %.2f\n", xVals[i], yVals[i]);
	}
	fclose(dataFile);
	return 0;
}
