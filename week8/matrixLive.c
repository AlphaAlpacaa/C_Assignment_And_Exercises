/*
This program shows how to create 2d arrays dynamically.
Try to understand the differences between printMatrix and printMatrix2
See: https://riptutorial.com/c/example/23264/pass-a-2d-array-to-a-function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef float real;

int randInt(int min, int max);
float randFloat(float min, float max, int precision);
real** generateMatrix(float min, float max, int row, int col);
void printMatrix(real** matrix, int row, int col);
void printMatrix2(real matrix[][3], int row);

int main()
{
	real testArr[3][3] = {{5.0f, 6.0f, 1.0f}, {5.0f, 6.0f, 1.0f}, {5.0f, 6.0f, 1.0f}}; //Static array (not dynamically created)
	real** matrix1 = generateMatrix(0.0f, 2.0f, 3, 3); //Dynamic
	real** matrix2 = generateMatrix(0.0f, 2.0f, 3, 3); //Dynamic
	int r,c;
	int col = 3;
	int row = 3;
	printMatrix(matrix1, 3, 3);
	printMatrix2(testArr, 3); //Try and see if you can print testArr with printMatrix. Discuss which way is better?
	
	return 0;
}

int randInt(int min, int max){
	int random;
	random = min+(rand()%(max-min+1));
	//printf("%d",random);
	return random;
}
float randFloat(float min, float max, int precision)
{
	min = min*pow(10,precision); 
	max = max*pow(10,precision);
	int randNum = randInt((int)min, (int)max);
	return (float)randNum/((float) pow(10,precision));
}

real** generateMatrix(float min, float max, int row, int col)
{
	int r;
	int c;
	real** matrix;
	matrix = malloc(row*sizeof(real));
	for(r=0; r<row; r++)
	{
		real* mat = malloc(col*sizeof(real)); //FOr rows
		for(c=0;c<col;c++)
		{
			mat[c] = randFloat(min, max, 2);
		}
		matrix[r] = mat;
	}
	return matrix;
}

void printMatrix(real** matrix, int row, int col)
{
	printf("Test\n");
	int r,c;
	printf("[ ");
	for(r=0;r<row;r++)
	{
		for(c=0;c<col;c++)
		{
			printf("%.1f ", matrix[r][c]);
		}
		printf("]\n");
	}
}
void printMatrix2(real matrix[][3], int row)
{
	printf("Test\n");
	int r,c;
	printf("[ ");
	for(r=0;r<row;r++)
	{
		for(c=0;c<3;c++)
		{
			printf("%.1f ", matrix[r][c]);
		}
		printf("]\n");
	}
}

