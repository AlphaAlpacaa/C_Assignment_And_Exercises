#include<stdio.h>

int main(){
	while(1){
		char letter=getchar();
		if(letter=='a'){
			letter=getchar();
			if(letter=='b'){
				letter=getchar();
				if(letter=='c'){
					printf("Started\n");
					while(1){
						letter=getchar();
						if(letter=='c'){
							letter=getchar();
							if(letter=='b'){
								letter=getchar();
								if(letter=='a'){
									printf("Ended\n");
								}
							}
						}
						else if(letter=='d'){
							letter=getchar();
							if(letter=='e'){
								letter=getchar();
								if(letter=='f'){
									printf("Action1\n");
								}
							}
						}
						else if(letter=='g'){
							letter=getchar();
							if(letter=='h'){
								letter=getchar();
								if(letter=='i'){
									printf("Action2\n");
								}
							}
						}
						else if(letter=='j'){
							letter=getchar();
							if(letter=='k'){
								letter=getchar();
								if(letter=='l'){
									printf("Action3\n");
								}
							}
						}
						else if(letter=='x'){
							letter=getchar();
							if(letter=='y'){
								letter=getchar();
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
