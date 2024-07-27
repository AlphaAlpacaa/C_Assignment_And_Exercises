#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int road_length = 50;
int max_step = 5;
int *runnerList;
void ShowPositions(int *runnerList, int runnerNumber);
int NextTurn(int *runnerList, int runnerNumber);
int n, j, o, q, a, i;
char key, quit;
int road, sum;


int main(){
	int * runnerList = (int * )calloc(n, sizeof(int));
	printf(" enter the number of competitors");
	scanf("%d",&n);
	ShowPositions((int*)runnerList,i);
	printf("Press C to start racing and then press ENTER to move on");
	scanf("%d",&key);
	
	if(key = 'c'){
		NextTurn((int*)runnerList,n);
	}
	quit=getchar();
	while(getchar()!='q'){
		
		for(o=1; o<=n; o++){
			printf("--------------------------------------------------------------\n");
			printf("RUNNER %d |",o);
			printf("%[]*\n ",NextTurn((int * )runnerList,n));
			printf("-------------------------------------------------------------\n");
			if(runnerList[o-1]>=road_length){
				printf("GAME OVER\n");
				printf("RUNNER %d WON",o);		
					break;
			}
		
		}
		if(runnerList[o-1]>=road_length){
			break;
		}
	}
}

int NextTurn(int *runnerList, int runnerNumber){
		srand(time(NULL));
		road=rand() % 5 + 1;
		for(j=1; j<=sum; j++){
			printf(" ");
			runnerList[o-1]=sum;
		}	
		sum+=road;			
}

void ShowPositions(int *runnerList , int runnerNumber){
		
		for(a=1; a<=n; a++){
		printf("------------------------------------------------\n");
		printf("RUNNER %d |[]*\n",a);
		printf("------------------------------------------------\n");
		}	
			
}
