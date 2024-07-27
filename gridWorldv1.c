/*
Treasure Search
Search the treasure with simple feedback in a gridworld
*/

#include <stdio.h>
#include <math.h>

//Global variables (Can we avoid this?)
int worldWidth = 40;
int worldHeight = 40;
int playerX = 20;
int playerY = 20;
int treasureX = 12;
int treasureY = 6;
	
void drawWorld(int width, int height, int playerPosX, int playerPosY);
int movePlayer(move);
float calculateDistance();

int main()
{
	//When learning random, use 
	float currentDistance = calculateDistance(); //Manhattan or Euclidian?
	drawWorld(worldWidth, worldHeight, playerX, playerY);
	while (1)
	{
		
		char move = 0;
		printf("Select your move (4:Left, 6:Right, 8:Up, 2:Down)\n");
		fflush(stdin);
		scanf("%c", &move);
		if(move == 0)
		{
			break;
		}else{
			movePlayer(move);
			drawWorld(worldWidth, worldHeight, playerX, playerY);
			float newDistance = calculateDistance();
			
			//Check if reached the treasue
			if(playerX == treasureX && playerY == treasureY)
			{
				printf("Found the treasure!\n");
				break;
			}
			else if(newDistance > currentDistance)
			{
				printf("Colder\n");
			}else if(newDistance < currentDistance)
			{
				printf("Warmer\n");
			}
			currentDistance = newDistance;
		}
	}

}

void drawWorld(int width, int height, int playerPosX, int playerPosY)
{
	for(int h=0;h<height;h++);
	{
		for(int w=0;w<width;w++)
		{
			if(w == 0 || h == 0 || (h == height-1) || (w==width-1))
			{
				printf("#");
			}
			else if(w == playerPosX && h == playerPosY)
			{
				printf("@");
			}else{
				printf(" ");
			}
		}
		putchar('\n');
	}
}
int movePlayer(move)
{
	int candidX;
	int candidY;
	switch(move)
	{
		case 'a':
		case 'A':
		case '4':
			candidX = playerX - 1;
			candidY = playerY;
			break;
		case 'd':
		case 'D':
		case '6':
			candidX = playerX + 1;
			candidY = playerY;
			break;
		case 's':
		case 'S':
		case '2':
			candidX = playerX;
			candidY = playerY + 1;
			break;
		case 'w':
		case 'W':
		case '8':
			candidX = playerX;
			candidY = playerY - 1;
			break;
	}
	
	if(candidX > 1 && candidX < (worldWidth-1) && candidY > 1 && (candidY < worldHeight - 1))
	{
		playerX = candidX;
		playerY = candidY;
		return 1;
	}
	return 0;
}
float calculateDistance()
{
	return (abs(playerX-treasureX) + abs(playerY-treasureY));
}
