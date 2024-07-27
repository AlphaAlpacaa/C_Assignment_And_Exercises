#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int randInt(int min, int max);
float randFloat(float min, float max, int precision);

void wait(int seconds);
int main()
{
	
	srand((unsigned)time(0));
	int i;
	for(i=0;i<10;i++)
	{
		printf("%f\n",randFloat(5,12,2));
	}
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


void wait(int seconds)
{
	int start = time(0);
	int end = time(0);
	printf("Starting waiting\n");
	while((end-start) < seconds)
	{
		//Wait
		end = time(0);
	}
	printf("Time is up!\n");
}



