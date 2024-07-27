/*
Treasure Search
Search the treasure with simple feedback in a gridworld
*/

#include <stdio.h>
#include <math.h>
int drawWorld (void){
int worldWidth = 40;
int worldHeight = 40;
int playerX = 20;
int playerY = 20;
int treasureX = 12;
int treasureY = 6;
	int i, j;
	for(i=1;i<=worldWidth;i++){
		
		printf("#");
	}
	printf("\n");
	for(i=1;i<=worldHeight;i++){
		
		printf("#");
		
		for(j=1;j<=worldHeight-2;j++){
			printf(" ");
			
		}
		printf("#\n");
	}
	for(i=1;i<=worldWidth;i++){
		
		printf("#");
	}
}
//Global variables (Can we avoid this?)
int main(){

int worldWidth = 40;
int worldHeight = 40;
int playerX = 20;
int playerY = 20;
int treasureX = 12;
int treasureY = 6;
drawWorld();
return 0;
}
