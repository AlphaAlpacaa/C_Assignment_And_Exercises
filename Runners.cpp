#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#define ROAD_LENGTH 50
#define MAX_STEP 6

void ShowPositions(int *runnerList, int runnerNumber, int size,  int step); 
	

int NextTurn(int *runnerList, int runnerNumber); 

int main(){
	int Number, size, *runnerList, step;
	printf("Enter how many runners there will be:");
	scanf("%d",&Number);
	int runnerNumber[Number];
	for(int i=0;i<Number;i++){
		runnerNumber[i] = 0;
		size=i;
	for(step=0;step<size;step++){
			for(int i=0;i<60;i++){
				printf("-");
			}
		printf("\nRunner %d |\n",runnerNumber[step]);
		if(step==size-1){
			for(int i=0;i<60;i++){
				printf("-");	
			}
		}
	}
	}
	
	
	return 0;
}

void ShowPositions(int *runnerList,int runnerNumber[], int size, int step){
	for(int step=0;step<size;step++){
			for(int i=0;i<60;i++){
				printf("-");
			}
		printf("\nRunner %d |\n", runnerNumber[step]);
		step+=1;
		if(step==size-1){
			for(int i=0;i<60;i++){
				printf("-");	
			}
		}
	}
}

/*int NextTurn(){
	
}*/
