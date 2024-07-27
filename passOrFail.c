/*
 Intro To C - Week 1
 Pass Or Fail
 Enter grades of your last 3 course and see if you fail or pass
*/

#include <stdio.h>
#define CURRENT_GPA 2
#define TAKEN_CREDITS 130
#define COURSE_CREDIT_1 3
#define COURSE_CREDIT_2 3
#define COURSE_CREDIT_3 3

int main()
{
	char grade[2];
	char grade1[2];
	char grade2[2];
	char grade3[2];
	char isCorrect;
	float totalCredits=TAKEN_CREDITS;
	float totalGrade = TAKEN_CREDITS*CURRENT_GPA;
	int correct; //See line 155

	//Think about what does this 'do-while' loop does
	do{
		//Course 1
		printf("Enter your first grade:\n");
		scanf("%s", grade1);
		if(!strcmp(grade1,"AA") || !strcmp(grade1,"aa"))
		{
			totalGrade += 4.0f*COURSE_CREDIT_1;
		}
		else if(!strcmp(grade1,"BA") || !strcmp(grade1,"ba") || !strcmp(grade1,"AB") || !strcmp(grade1,"ab"))
		{
			totalGrade += 3.5f*COURSE_CREDIT_1;
		}
		else if(!strcmp(grade1,"BB") || !strcmp(grade1,"bb"))
		{
			printf("asdasdad\n");
			totalGrade += 3.0f*COURSE_CREDIT_1;
		}
		else if(!strcmp(grade1,"CB") || !strcmp(grade1,"cb") || !strcmp(grade1,"BC") || !strcmp(grade1,"bc"))
		{
			totalGrade += 2.5f*COURSE_CREDIT_1;
		}
		else if(!strcmp(grade1,"CC") || !strcmp(grade1,"cc") )
		{
			totalGrade += 2.0f*COURSE_CREDIT_1;
		}
		else if(!strcmp(grade1,"DC") || !strcmp(grade1,"dc") || !strcmp(grade1,"CD") || !strcmp(grade1,"cd"))
		{
			totalGrade += 1.5f*COURSE_CREDIT_1;
		}
		else if(!strcmp(grade1,"DD") || !strcmp(grade1,"dd") )
		{
			totalGrade += 1.0f*COURSE_CREDIT_1;
		}else if(!strcmp(grade1,"FF") || !strcmp(grade1,"ff") )
		{
			totalGrade += 0.0f;
		}
		else{
			printf("Please enter a valid grade\n");
			return 0;
		}
		totalCredits += COURSE_CREDIT_1;
		
		//Course 2
		printf("Enter your second grade\n");
		scanf("%s",grade2);
		
		if(!strcmp(grade2,"AA") || !strcmp(grade2,"aa"))
		{
			totalGrade += 4.0f*COURSE_CREDIT_2;
		}
		else if(!strcmp(grade2,"BA") || !strcmp(grade2,"ba") || !strcmp(grade2,"AB") || !strcmp(grade2,"ab"))
		{
			totalGrade += 3.5f*COURSE_CREDIT_2;
		}
		else if(!strcmp(grade2,"BB") || !strcmp(grade2,"bb"))
		{
			totalGrade += 3.0f*COURSE_CREDIT_2;
		}
		else if(!strcmp(grade2,"CB") || !strcmp(grade2,"cb") || !strcmp(grade2,"BC") || !strcmp(grade2,"bc"))
		{
			totalGrade += 2.5f*COURSE_CREDIT_2;
		}
		else if(!strcmp(grade2,"CC") || !strcmp(grade2,"cc") )
		{
			totalGrade += 2.0f*COURSE_CREDIT_2;
		}
		else if(!strcmp(grade2,"DC") || !strcmp(grade2,"dc") || !strcmp(grade2,"CD") || !strcmp(grade2,"cd"))
		{
			totalGrade += 1.5f*COURSE_CREDIT_2;
		}
		else if(!strcmp(grade2,"DD") || !strcmp(grade2,"dd") )
		{
			totalGrade += 1.0f*COURSE_CREDIT_2;
		}else if(!strcmp(grade2,"FF") || !strcmp(grade2,"ff") )
		{
			totalGrade += 0.0f;
		}
		else{
			printf("Please enter a valid grade\n");
			return 0;
		}
		totalCredits += COURSE_CREDIT_2;
		
		//Course 3
		printf("Enter your third grade\n");
		scanf("%s",grade3);
		if(strcmp(grade3,"AA") || strcmp(grade3,"aa"))
		{
			totalGrade += 4.0f*COURSE_CREDIT_3;
		}
		else if(strcmp(grade3,"BA") || strcmp(grade3,"ba") || strcmp(grade3,"AB") || strcmp(grade3,"ab"))
		{
			totalGrade += 3.5f*COURSE_CREDIT_3;
		}
		else if(strcmp(grade3,"BB") || strcmp(grade3,"bb"))
		{
			totalGrade += 3.0f*COURSE_CREDIT_3;
		}
		else if(!strcmp(grade3,"CB") || !strcmp(grade3,"cb") || !strcmp(grade3,"BC") || !strcmp(grade3,"bc"))
		{
			totalGrade += 2.5f*COURSE_CREDIT_3;
		}
		else if(!strcmp(grade3,"CC") || !strcmp(grade3,"cc") )
		{
			totalGrade += 2.0f*COURSE_CREDIT_3;
		}
		else if(!strcmp(grade3,"DC") || !strcmp(grade3,"dc") || !strcmp(grade3,"CD") || !strcmp(grade3,"cd"))
		{
			totalGrade += 1.5f*COURSE_CREDIT_3;
		}
		else if(!strcmp(grade3,"DD") || !strcmp(grade3,"dd") )
		{
			totalGrade += 1.0f*COURSE_CREDIT_3;
		}else if(!strcmp(grade3,"FF") || !strcmp(grade3,"ff") )
		{
			totalGrade += 0.0f*COURSE_CREDIT_3;
		}
		else{
			printf("Please enter a valid grade\n");
			return 0;
		}
		totalCredits += COURSE_CREDIT_3;
		
		printf("Your grades are %s, %s and %s\n", grade1, grade2, grade3);
		printf("Is this correct(y/n)?\n");
		getchar(); //Comment this to see the effects;
		isCorrect = getchar();
		if(isCorrect == 'y')
		{
			correct = 1;
			float finalGpa = totalGrade / totalCredits;
			if(finalGpa >= 2.0f)
			{
				printf("You pa with a gpa of %f\n", finalGpa);
			}else{
				printf("You have failed with a gpa of %f\n", finalGpa);
			}
		}
		else
		{
			correct = 0;
			printf("Rerun the program");
		}
	}while(!correct);

	return 0;
}
