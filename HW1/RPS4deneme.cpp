#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

int randInt(int min, int max)  //choose a random number for computerChoice(1-3)
{
	int random;
	random = min+ (rand()%(max-min+1)); 
	return random;
}

int randInt2(int min, int max) //choose a random number for computerChoice after first 5 moves(1-10)
{
	int random2;
	random2 = min+ (rand()%(max-min+1)); 
	return random2;
}

int main()
{
	int UserScore=0, CompScore=0, Rock=0, Scissor=0, Paper =0, CompRock=0, CompPaper=0, CompScissor=0, CompChoice, UserChoice; //define variables
	
	srand((unsigned)time(0));  //for changing random numbers every start
	int i=0; //define counter
	char input[1]; 	
	while(i<15) //while loop for r-p-s game
	{
		while(1){ //while loop for input and invalid values
		printf("Choose your move:\n");
		printf("r for ROCK\n");
		printf("p for PAPER\n");
		printf("s for SCISSOR\n");
		printf("Please Enter:\n");
		scanf("%s", &input);  //take input value with scanf function
		if(!strcmp(input,"r"))  //convert answer to decimal numbers
		{
			UserChoice=1;
			break;
		}
	 	else if(!strcmp(input,"p")) //convert answer to decimal numbers
		{
			UserChoice=2;
			break;
		}
	 	else if(!strcmp(input,"s")) //convert answer to decimal numbers
		{
			UserChoice=3;
			break;
		}
		else{		//error for any invalid value
			printf("Please Try Again\n");
		}
		}
		
		int CompChoice = (rand()%3) + 1; //choose number 1 to 3 for r-p-s randomly for ComputerChoice

		if(i>=5){ 	//learning and counterattack time
			float RockChance = (float(Rock))/(float(Rock + Paper + Scissor)); //define chance of rock
			float PaperChance = (float(Paper))/(float(Rock + Paper + Scissor)); //define chance of paper
			float ScissorChance = (float(Scissor))/(float(Rock + Paper + Scissor)); //define chance of scissor
			int CompChoice2 =(rand()%10) + 1; //choose number 1 to 10 for r-p-s randomly for ComputerChoice
			
			if(CompChoice2 <= ((RockChance)*10)) //comparison with the user's rock selection rate
			{
				CompChoice=2; //the computer chooses paper as a move against the rock
			}
			else if(CompChoice2 <= ((RockChance+PaperChance)*10)) //comparison with the user's paper selection rate
			{
				CompChoice=3; //the computer chooses scissor as a move against the paper
			}
			else  //comparison with the user's scissor selection rate
			{
				CompChoice=1; //the computer chooses rock as a move against the scissor
			}
		}
		if((UserChoice==1&CompChoice==3)||(UserChoice==2&CompChoice==1)||(UserChoice==3&CompChoice==2)){ //user won situations
			if(CompChoice==1){
				printf("Computer->Rock\n"); //printing computer moves
				CompRock++;  //computer moves counter
			}
			else if(CompChoice==2){
				printf("Computer->Paper\n"); //printing computer moves
				CompPaper++;  //computer moves counter
			}
			else{
				printf("Computer->Scissor\n"); //printing computer moves
				CompScissor++;   //computer moves counter
			}
			UserScore++; //user score counter
			printf("You won\n"); //printing winner
			if (UserChoice==1){
				Rock++;	 //user moves counter
			}
			else if(UserChoice==2){
				Paper++; //user moves counter
			}
			else{
				Scissor++; //user moves counter
			}
		}
		else if((UserChoice==3&CompChoice==1)||(UserChoice==1&CompChoice==2)||(UserChoice==2&CompChoice==3)){ //computer won situations
			if(CompChoice==1){
				printf("Computer->Rock\n"); //printing computer moves
				CompRock++; //computer moves counter
			}
			else if(CompChoice==2){
				printf("Computer->Paper\n"); //printing computer moves
				CompPaper++; //computer moves counter
			}
			else{
				printf("Computer->Scissor\n"); //printing computer moves
				CompScissor++; //computer moves counter
			}
			CompScore++; //computer score counter
			printf("Computer won\n"); //printing winner
			if (UserChoice==1){
				Rock++;	 //user moves counter
			}
			else if(UserChoice==2){
				Paper++; //user moves counter
			}
			else{
				Scissor++; //user moves counter
			}
		}
		else{ //draw situations
			if(CompChoice==1){
				printf("Computer->Rock\n");
				CompRock++; //computer moves counter
			}
			else if(CompChoice==2){
				printf("Computer->Paper\n");
				CompPaper++; //computer moves counter
			}
			else{
				printf("Computer->Scissor\n");
				CompScissor++; //computer moves counter
			}
			
			printf("Draw\n"); //printing situation
			if (UserChoice==1){
				Rock++;	 //user moves counter
			}
			else if(UserChoice==2){
				Paper++; //user moves counter
			}
			else{
				Scissor++; //user moves counter
			}
		}
		i++; //add 1 to counter
	printf("User:%d\nComputer:%d\n",UserScore,CompScore); //printing score board
	
		if(i>5){
			
			printf("Computer Rock Selection Number:%d,User Rock Selection Number:%d\n",CompRock,Rock);		//printing all moves 
			printf("Computer Paper Selection Number:%d,User Paper Selection Number:%d\n",CompPaper,Paper);
			printf("Computer Scissor Selection Number:%d,User Scissor Selection Number:%d\n",CompScissor,Scissor);
		}		
	}
	if(UserScore>CompScore) 
	{
		printf("You won this game"); //priting result
	}
	else if(CompScore>UserScore) 
	{
		printf("Computer won this game"); //priting result
	}
	else 
	{
		printf("Draw\n"); //priting result
	}
	return 0;
}
