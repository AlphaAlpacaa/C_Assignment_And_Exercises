#include<stdio.h>

int main(){
	int c[10],max,min,j,i,number; // define variables which type of integer and array
	float total;                // define float variables
	for (i=0;i<10;i++){			  // for loop 
		printf("Enter a number:");// asks for a number 
		scanf("%d", &c[i]);       // take a number and add in a c array
		if (i == 0){
			min = max = c[i];     // the first number is bot maximum and minimum poimnt of the array
		}
		if (c[i]<min){			  // check the number whether it is smaller than the previous ones or not
			min =c[i];			  // if it is small, it is our new minimum number
		}
		if (c[i]>max){			  // check the number whether it is bigger than the previous ones or not
			max =c[i];			  // if it is big, it is our new maximum number
		}
		total += c[i]	;		  // add a new number to total 
		printf("Maximum=%d Minimum=%d Average = %f\n",max,min,(total/(i+1))); // printing our max min average values (to find a average value-> divide the number of elements by the sum)
	}
	printf("End of program");     // printing end of program
	return 0;
}
