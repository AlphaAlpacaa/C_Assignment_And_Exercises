#include <stdio.h>

int strLength(char *chPtr){
	int length = 0,i;   
	for (i = 0; chPtr+i != '\0'; i++)
    {
        length++;
    }
    return length;
}

int main(){
	char b[]="Say";
	int *chPtr=&b;
	printf("%d",strLength(*chPtr));
	return 0;
}
