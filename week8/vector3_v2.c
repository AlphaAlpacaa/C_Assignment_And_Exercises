/*
See the differences between crossProduct and crossProduct2. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int randInt(int min, int max);
float randFloat(float min, float max, int precision);

float* generateVector(float min, float max, int size);
void printVector(float* vec, int size);

float dotVector(float* vec1, float* vec2, int size);
void crossProduct(float* vec1, float* vec2, float* result); 
void crossProduct2(float* vec1, float* vec2, float** result); //Dynamically creates an array inside


int main()
{
	srand(0);
	float *vec1 = generateVector(0.0f, 1.0f, 3);
	float *vec2 = generateVector(0.0f, 1.0f, 3);
	
	float regArray[3] = {0.2f, 0.5f, 0.8f};
	printVector(vec1, 3);
	printVector(vec2, 3);
	float dotProd = dotVector(vec1, vec2, 3);
	
	float crossProd[3]; //This has memory in the meap
	float* crossProd2; //This is just a pointer, no memory allocated
	crossProduct(vec1, vec2, crossProd);
	crossProduct2(vec1, vec2, &crossProd2);
	printVector(crossProd2, 3);
	return 0;
}

float* generateVector(float min, float max, int size)
{

	float* vec = malloc(sizeof(float)*size); 
	for(int i=0;i<size;i++)
	{
		vec[i] = randFloat(min,max,2);
	}
	printf("%Inside %p\n", vec);
	return vec;
}
void printVector(float* vec, int size)
{
	int i;
	printf("[");
	for(int i=0;i<size;i++)
	{
		printf("%.2f, ", vec[i]);
	}
	printf("]\n");
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
float dotVector(float* vec1, float* vec2, int size)
{
	int i;
	float sum = 0;
	for(i=0;i<size;i++)
	{
		sum += vec1[i]*vec2[i];
	}
	return sum;
}
void crossProduct(float* vec1, float* vec2, float* result)
{
	result[0] = vec1[1]*vec2[2] - vec2[2]*vec1[1];
	result[1] = vec1[2]*vec2[0] - vec1[0]*vec2[2];
	result[2] = vec1[0]*vec2[1] - vec2[0]*vec1[1];
}
void crossProduct2(float* vec1, float* vec2, float** result)
{
	*result = malloc(3*sizeof(float)); //Allocate mem to the pointer that result points to
	(*result)[0] = vec1[1]*vec2[2] - vec2[2]*vec1[1];
	(*result)[1] = vec1[2]*vec2[0] - vec1[0]*vec2[2];
	(*result)[2] = vec1[0]*vec2[1] - vec2[0]*vec1[1];
}
