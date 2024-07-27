#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#define ROAD_LENGTH 50
#define MAX_STEP 6

void ShowPositions(int *runnerList, int runnerNumber, int runnerPositions[]); //define a function

int NextTurn(int *runnerList, int runnerNumber, int runnerPositions[]);  //define a function

int  runnerNumber, *runnerList, step;	 //define variables

int main(){
	srand((unsigned)time(0));
	printf("Enter how many runners there will be:");
	scanf("%d",& runnerNumber); //take a number of runners
	int runnerPositions[runnerNumber];  //define a runnerPosition array
	for(int i=0;i< runnerNumber;i++){
		runnerPositions[i] = 0; //define runnerpositions as zero
	}
	runnerList= &step;
	int winnersNumber=0, winners[100], quit; //define variables
	quit=getchar();
	printf("Press Enter to Start Race\n");
	while(getchar()!='e'){	
		printf("Press Enter to Continue Race\n");
		NextTurn(runnerList, runnerNumber, runnerPositions); //call functions
		ShowPositions(runnerList,runnerNumber,runnerPositions);  //call functions
		int count=0, whichWinner; //define variables
		for(int b=0;b<runnerNumber;b++){
			if(runnerPositions[b]>=ROAD_LENGTH){ //win condition
				whichWinner=b+1; //for the only winner
				winnersNumber+=1; //for the multiple winner
				winners[count]=b+1; //for the multiple winner
				count+=1; //for the multiple winner
			}	
		}
		if(winnersNumber>1){ //for the multiple winner, we choose the real winner randomly using rand func 
			int winnersChance[100];
			srand((unsigned)time(0));
			for(int c=0;c<winnersNumber;c++)
			{
				winnersChance[c]=rand()%999; //a random number is chosen for the winners
			}
			int max=winnersChance[0];
			int maxNumber=winners[0];
			for(int c=0;c<winnersNumber;c++)
			{
				if(max<winnersChance[c]){ //choose maximum random number
					maxNumber=winners[c];
				}
			}
			printf("Runner%d is Winner\n",maxNumber); //printing winner(multiple winner)
			break;
		}
		else if(winnersNumber==1){
			printf("Runner%d is Winner\n",whichWinner); //printing winner (only winner)
			break;
		}
	}	
	return 0;
}

void ShowPositions(int *runnerList, int runnerNumber, int runnerPositions[]){ //create a function for show race stadium and runners
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

int NextTurn(int *runnerList, int runnerNumber, int runnerPositions[]){  //create a function for that makes up the runners' moves
	for(int i=0;i<runnerNumber;i++){
		step=(rand()%MAX_STEP)+1;
		runnerPositions[i]+=step;
		printf("runner%d = %d and RunnerPosition = %d\n",(i+1),step,runnerPositions[i]);
	}
	
}


