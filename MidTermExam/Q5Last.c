#include<stdio.h>

int main(){
	while(1){
		char letter;
		scanf("%s",&letter);
		if(letter=='a'){
			scanf("%s",&letter);
			if(letter=='b'){
				scanf("%s",&letter);
				if(letter=='c'){
					printf("Started\n");
					while(1){
						scanf("%s",&letter);
						if(letter=='c'){
							scanf("%s",&letter);
							if(letter=='b'){
								scanf("%s",&letter);
								if(letter=='a'){
									printf("Ended\n");
								}
							}
						}
						else if(letter=='d'){
							scanf("%s",&letter);
							if(letter=='e'){
								scanf("%s",&letter);
								if(letter=='f'){
									printf("Action1\n");
								}
							}
						}
						else if(letter=='g'){
							scanf("%s",&letter);
							if(letter=='h'){
								scanf("%s",&letter);
								if(letter=='i'){
									printf("Action2\n");
								}
							}
						}
						else if(letter=='j'){
							scanf("%s",&letter);
							if(letter=='k'){
								scanf("%s",&letter);
								if(letter=='l'){
									printf("Action3\n");
								}
							}
						}
						else if(letter=='x'){
							scanf("%s",&letter);
							if(letter=='y'){
								scanf("%s",&letter);
								if(letter=='z'){
									printf("Quitting\n");
									break;
								}
							}
						}
					}
					break;
				}
			}
		}
	}
	return 0;
}
