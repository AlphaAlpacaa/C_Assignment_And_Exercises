#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 

int main(){
	int digits=0,lowercase_letters=0,punctuation_characters=0,white_space_characters=0,uppercase_letters=0,alphabetic_character=0;
	char input[200];
	printf ("Please write any text:\n");
	fgets (input, 200, stdin);
	
	for(int counter=0;counter != strlen(input);counter++){
		if(isalpha(input[counter])){
			alphabetic_character++;
			if(isupper(input[counter])){
				printf("%c is a upper case letter\n", input[counter]); 
				uppercase_letters++;
			}
			else if(islower(input[counter])){
				printf("%c is a lower case letter\n", input[counter]); 
				lowercase_letters++;
			}	
		}
		else if(isdigit(input[counter])){
			printf("%c is a digit\n", input[counter]); 
			digits++;
		}
		else if(ispunct(input[counter])){
			printf("%c is a punctuation\n", input[counter]);
			punctuation_characters++;
		}
		else if(counter+1 != strlen(input) && isspace(input[counter])){
			printf("%c is a whitespace\n", input[counter]);
			white_space_characters++;
		}			
	}
	printf(
		"total letters:%d\nlower case letters:%d\nupper case letters:%d\ndigits:%d\nwhitespaces:%d\npunctuations:%d\ntotal characters:%d", 
		alphabetic_character,lowercase_letters,uppercase_letters,digits,white_space_characters,punctuation_characters,alphabetic_character+digits+white_space_characters+punctuation_characters);
		
	return 0;
}


