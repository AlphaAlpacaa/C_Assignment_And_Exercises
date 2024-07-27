#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int randInt(int min, int max);
float randFloat(float min, float max, int precision);
float f_x(float x);
float areaUnderCurve(float a, float b);

int main()
{
	srand((unsigned)time(0));
	
	printf("Area under curve:%f \n", areaUnderCurve(0,10));
	printf("Correct one %f\n", 1000.0f/3);
}


float areaUnderCurve(float a, float b)
{
	//Generate points
	int maxNums = 50000;
	int pointsUnderCurve = 0;
	int i;
	for(i=0;i<maxNums;i++)
	{
		float randX = randFloat(a, b, 2);
		float randY = randFloat(0, f_x(b), 2);
		
		if(randY < f_x(randX))
		{
			pointsUnderCurve++;
		}
	}
	
	return ((float)pointsUnderCurve/(float)maxNums)*(f_x(b)*(b-a));
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
	return (float)randNum/((float) pow(10,2));
}
