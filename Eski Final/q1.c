#include<stdio.h>



int main(){
	char mail[50];
	char pw[20];
	printf("Enter email: ");
	scanf("%s",mail);
	printf("Enter password: ");
	scanf("%s",pw);
	if (CheckCredentials(mail,pw)==1){
		printf("correct!");
	}
	else printf("wrong!");
	
	
	return 0;
}

int CheckCredentials(char email[],char pw[]){
	int i = 0;
	int checkmail = 0;
	int checkpw[3] = {0};
	for(i=0; email[i]!='\0' ;i++){   
		if(email[i] == '@'){ 
			for(; email[i]!='\0'; i++){     
				if(email[i] == '.' ){
					checkmail=1;
				 	break;
				}  	
			}   
		} 
	}
	for(i=0; pw[i]!='\0';i++){
		if(pw[i]>='A'&& pw[i]<='Z'){
			checkpw[0]=1;
		}
		else if(pw[i]>='a'&& pw[i]<='z'){
			checkpw[1]=1;
		}
		else if(pw[i]>='0'&& pw[i]<='9'){
			checkpw[2]=1;
		}
	}
		if (checkmail==1 && checkpw[0]==1 && checkpw[1]==1 && checkpw[2]==1){
			return 1;
		}
		else return 0;
}
