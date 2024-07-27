#include<stdio.h>

int strLength(char str[20]){
	char *pt;
	int i=0;			
    pt = str;
  
    while (*pt != '\0') {
    	pt++;
    	i++;
  	}
	
	return i;
}

int main(){
  
  	char str[20], *pt;
  
  	gets(str);
  	

  	printf("%d",strLength(str) );

  	return 0;
}
