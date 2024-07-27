#include<stdio.h>

int f(int);  // declaration of the function 

int main(){
	int n;   // define a term variable
	printf("Which value of n do you want?"); // asks which term would you want
	scanf("%d",&n); 	// take the term variable as n
	printf("%d",f(n));  // printing n th term 
	return 0;
}


int f(int n){		    // definition of the function	 
	if(1<=n && n<=3){	// in the range of 1 to 3 
		return 1;		// return '1' value according to definition
	}
	else if(3<n){   	// in order to find n th term in principal value range 
		return f(n-1)+2*f(n-2)+3*f(n-3); // return function
	}
	else{  			// for invalid numbers
		return -1;  // return '-1' value
	}
}
