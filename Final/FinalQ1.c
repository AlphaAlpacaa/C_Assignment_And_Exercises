#include<stdio.h>

int CheckCredentials(char email[],char pw[]);

int main(){
	char email[30], pw[25];
	printf("Email: ");
	scanf("%s",email);
	printf("Password: ");
	scanf("%s",pw);
	if (CheckCredentials(email,pw)==1){
		printf("1");
	}
	else{
		printf("0");
	}

	return 0;
}

int CheckCredentials(char email[],char pw[]){
	int counter =0;
	int check_email = 0;
	int check_pw[3] = {0};
	for(counter=0;email[counter]!='\0';counter++){   
		if(email[counter] == '@'){ 
			for(;email[counter]!='\0';counter++){     
				if(email[counter] == '.'){
					check_email=1;
				 	break;
				}  	
			}   
		} 
	}
	
	for(counter=0; pw[counter]!='\0';counter++){
		if(pw[counter]>='a'&& pw[counter]<='z'){
			check_pw[1]=1;
		}
		else if(pw[counter]>='A'&& pw[counter]<='Z'){
			check_pw[0]=1;
		}
		else if(pw[counter]>='0'&& pw[counter]<='9'){
			check_pw[2]=1;
		}
	}
		if (check_email==1 && check_pw[0]==1 && check_pw[1]==1 && check_pw[2]==1){
			return 1;
		}
		else{
			return 0;
		}
}
