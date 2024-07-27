#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randInt(int min, int max);

	
int main(){
	int min,max;
	printf("Lutfen minimum degeri girin:");
	scanf("%d",&min);
	printf("Lutfen maximum degeri girin:");
	scanf("%d",&max);
	randInt(min, max);
	
}

int randInt(int min, int max){
	int random;
	random = min+(rand()%(max-min+1));
	printf("%d",random);
	return random;
}	
