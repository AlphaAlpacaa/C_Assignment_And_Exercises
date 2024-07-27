#include <stdio.h>

int checkCollision(float rect1[4], float rect2[4]){
	if(((rect1[0]>rect2[0])&&(rect1[0]>rect2[0]+rect2[2]))||((rect2[0]>rect1[0])&&(rect2[0]>rect1[0]+rect1[2]))||((rect1[1]>rect2[1])&&(rect1[1]>rect2[1]+rect2[3]))||((rect2[1]>rect1[1])&&(rect2[1]>rect1[1]+rect1[3])))    
		return 0;	
	else{
		return 1;	
	}           
}

