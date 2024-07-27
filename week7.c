/*
This code doesn't work in its current state. See if you can correct the errors
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

int main()
{
	srand(0);
	float *vec1 = generateVector(0.0f, 1.0f, 3);
	float *vec2 = generateVector(0.0f, 1.0f, 3);
	printVector(vec1, 3);
	printVector(vec2, 3);
	//float vec1[3] = {0.5f, 0.2f, 1.0f};
	//float vec2[3] = {0.8f, 0.8f, 0.3f};
	float dotProd = dotVector(vec1, vec2, 3);
	float *crossProd;
	crossProduct(vec1, vec2, crossProd);
		printf("in result %p\n", crossProd);
	//printf("Dot product %f\n", dotProd);
	printVector(crossProd, 3);
	return 0;
}

float* generateVector(float min, float max, int size)
{
	float x;
	float y;
	float vec[size];
	for(int i=0;i<size;i++)
	{
		vec[i] = randFloat(min,max,2);
	}

	/*while(1){
		
		
		x=randFloat(min,max,2);
		y=randFloat(min,max,2);
		if(x*x + y*y== size*size){
			break;
		}
		
	}*/
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
	float _result[3];
	_result[0] = vec1[1]*vec2[2] - vec2[2]*vec1[1];
	_result[1] = vec1[2]*vec2[0] - vec1[0]*vec2[2];
	_result[2] = vec1[0]*vec2[1] - vec2[0]*vec1[1];
	result = _result;
	printf("in result %p\n", result);
}
