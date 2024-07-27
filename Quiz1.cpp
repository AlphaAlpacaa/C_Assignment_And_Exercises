#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#define ROAD_LENGTH 50
#define MAX_STEP 6

void ShowPositions(int *runnerList, int runnerNumber, int runnerPositions[]); //define a function

int NextTurn(int *runnerList, int runnerNumber, int runnerPositions[]);  //define a function

int  runnerNumber, *runnerList, step;	 //define global variables

int main(){
	srand((unsigned)time(0));  
	printf("Enter how many runners there will be:");
	scanf("%d",& runnerNumber);
	int runnerPositions[runnerNumber];
	for(int i=0;i< runnerNumber;i++){
		runnerPositions[i] = 0;
	}
	runnerList= &step;
	int exit=1,winnersNumber=0, winners[100], quit;
	quit=getchar();
	printf("Press Enter to Start Race\n");
	while(getchar()!='e'){
		printf("Press Enter to Continue Race\n");
		NextTurn(runnerList, runnerNumber, runnerPositions);
		ShowPositions(runnerList,runnerNumber,runnerPositions);
		int count=0, whichWinner;
		for(int b=0;b<runnerNumber;b++){
			if(runnerPositions[b]>=ROAD_LENGTH){
				whichWinner=b+1;
				winnersNumber+=1;
				winners[count]=b+1;
				count+=1;
				exit=0;
			}	
		}
		if(winnersNumber>1){
			int winnersChance[100];
			srand((unsigned)time(0));
			for(int c=0;c<winnersNumber;c++)
			{
				winnersChance[c]=rand()%999;
			}
			int max=winnersChance[0];
			int maxNumber=winners[0];
			for(int c=0;c<winnersNumber;c++)
			{
				if(max<winnersChance[c]){
					maxNumber=winners[c];
				}
			}
			printf("Runner%d is Winner\n",maxNumber);
		}
		else if(winnersNumber==1){
			printf("Runner%d is Winner\n",whichWinner);
		}
		if(exit==0){
			break;
		}
		
	}
	
	return 0;
}

void ShowPositions(int *runnerList, int runnerNumber, int runnerPositions[]){
	int number=1;
	for(int i=0;i<runnerNumber;i++){
			for(int j=0;j<61;j++){
			printf("-");	
			}
		printf("\nRunner %d |",i+1);
		int sum=runnerPositions[i];
		for(int i=0;i<sum;i++){
			printf(" ");
		}
		printf("*\n");
	}	
	for(int j=0;j<61;j++){
		printf("-");	
	}
	printf("\n");
}

int NextTurn(int *runnerList, int runnerNumber, int runnerPositions[]){
	for(int i=0;i<runnerNumber;i++){
		step=(rand()%MAX_STEP)+1;
		runnerPositions[i]+=step;
		printf("runner%d = %d and RunnerPosition = %d\n",(i+1),step,runnerPositions[i]);
	}
	
}


