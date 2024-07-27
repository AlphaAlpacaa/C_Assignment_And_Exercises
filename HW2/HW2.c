#include <stdio.h>
#include <string.h>

int exists(const char *fname) //to check the existence of the current file
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

int main()
{   
    if (!exists("out.txt")) // if file does not exist create a file
    {
        FILE *fp;
        fp = fopen("out.txt", "w");
        fclose (fp);
    }
    int option=10, top_numb, k = 0, a = 0; //define variables (patient's variables and other counter and option variables)
    int i,l,m,x,y;
    int option_1, option_2, id, update_id;
    int patient_id;
    char patient_surname[20], patient_name[20];
    int new_id[100];
    char new_name[100][20];
    char new_surname[100][20];
    char new_birthday[100][20];
    char new_email[100][50];
    char new_department[100][20];

    FILE *infile; //assigning data from current file to arrays
    infile = fopen("out.txt", "r");
    while (!feof(infile))	
    {
        fscanf (infile,"%d %s %s %s %s %s", &new_id[a], &new_name[a][0], &new_surname[a][0], &new_birthday[a][0], &new_email[a][0], &new_department[a][0]);
        a++;
    }
    fclose (infile);
    k = a - 1;
    while (option != 0) // a loop continue without press '0'
    {   
        printf("\n0: Exit | "); // printing entries of management system
        printf("1: Show All Records | ");
        printf("2: Search Patient | ");
        printf("3: New Patient");
        printf("\nPlease select an option: ");
        scanf("%d",&option); // take an option for 0-1-2-3

        if (option == 1)
        {
            printf("\nPATIENT RECORDS:");
            for (i = 0; i < k; i++) //printing patient records 
            {   
                if (new_id[i] != -99)
                {
                    printf("\n\n%d   ",new_id[i]);
                    printf("%s   ",new_name[i]);
                    printf("%s   ",new_surname[i]);
                    printf("%s   ",new_birthday[i]);
                    printf("%s   ",new_email[i]);
                    printf("%s   ",new_department[i]);
                }
            }
            printf("\n\n\n0: Return to Main Menu | 1: Delete Record | 2: Update Record");
            printf("\nPlease select an option:");
            scanf("%d",&option_1);
            if (option_1 == 0)
            {
                /* Return to Main Menu */
            }
            else if (option_1 == 1)
            {
                printf("Patient Id: ");
                scanf("%d",&patient_id);

                for (i = 0; i < k; i++)
                {   
                    if (patient_id == new_id[i])
                    {   
                        new_id[i] = -99;		// delete the patient record 
                    }
                }
                printf("\nPatient record is deleted...\n");
                FILE *fp;
                fp = fopen("out.txt","w");                
                for (i = 0; i < k; i++)
                {   
                    if (new_id[i] != -99)
                    {
                        fprintf(fp,"%d   %s   %s   %s   %s   %s   ",new_id[i], new_name[i], new_surname[i], new_birthday[i], new_email[i], new_department[i]);
                        fprintf(fp,"\n");
                    }
                }   
                fclose (fp);
                           
            }
            else if (option_1 == 2)
            {   
                printf("Patient Id: ");
                scanf("%d",&update_id);
                FILE *fp;
                fp = fopen("out.txt","w");
                for (i = 0; i < k; i++)
                {   
                    if (update_id == new_id[i]) // update patient
                    {
                        printf("\nEnter Name (Old: %s): ", new_name[i]);
                        scanf("%s",&new_name[i][0]);
                        printf("\nEnter Surname (Old: %s): ", new_surname[i]);
                        scanf("%s",&new_surname[i][0]);
                        printf("\nEnter Birthday (Old: %s): ", new_birthday[i]);
                        scanf("%s",&new_birthday[i][0]);
                        printf("\nEnter E-Mail (Old: %s): ", new_email[i]);
                        scanf("%s",&new_email[i][0]);
                        printf("\nEnter Department (Old: %s): ", new_department[i]);
                        scanf("%s",&new_department[i][0]);
                        printf("\n Patient record is updated...\n\n");
                    }
                    if (new_id[i] != -99)
                    {
                        fprintf(fp,"%d   %s   %s   %s   %s   %s   ",new_id[i], new_name[i], new_surname[i], new_birthday[i], new_email[i], new_department[i]);
                        fprintf(fp,"\n");
                    }
                }
                fclose (fp);
            }
        }

        else if (option == 2)	//search ID
        {
            printf("\n0: Return to Main Menu | ");
            printf("1: Search By Id | ");
            printf("2: Search By Name | ");
            printf("3: Search By Surname");   
            printf("\nPlease select an option: ");
            scanf("%d",&option_2);

            if (option_2 == 0)
            {
                /*Return to Main Menu*/
            }
            if (option_2 == 1)
            {
                printf("Patient Id: ");
                scanf("%d",&id);
                printf("\n\nSerching...");
                l = 0;
                for (i = 0; i < k; i++)
                {   
                    if (id == new_id[i]) // printing specific patient according to ID
                    {
                        printf("\n%d   ",new_id[i]);
                        printf("%s   ",new_name[i]);
                        printf("%s   ",new_surname[i]);
                        printf("%s   ",new_birthday[i]);
                        printf("%s   ",new_email[i]);
                        printf("%s   ",new_department[i]);
                        l++;
                    }
                }
                printf("\nSearch completed. %d patient(s) are found...",l);
            }
            if (option_2 == 2)
            {
                printf("Patient Name: ");
                scanf("%s", patient_name);
                printf("\n\nSerching...");
                l = 0;
                for (i = 0; i < k; i++)
                {   
                    x=strcmp(&new_name[i][0],patient_name); // printing specific patients according to name
                    if (x == 0)
                    {
                        printf("\n%d   ",new_id[i]);
                        printf("%s   ",new_name[i]);
                        printf("%s   ",new_surname[i]);
                        printf("%s   ",new_birthday[i]);
                        printf("%s   ",new_email[i]);
                        printf("%s   ",new_department[i]);
                        l++;
                    }
                }
                printf("\nSearch completed. %d patient(s) are found...",l);
            }
            if (option_2 == 3)
            {
                printf("Patient Surname: ");
                scanf("%s", patient_surname);
                printf("\n\nSerching...");
                l = 0;
                for (i = 0; i < k; i++)
                {   
                    x=strcmp(&new_surname[i][0],patient_surname); // printing specific patients according to surname
                    if (x == 0)
                    {
                        printf("\n%d   ",new_id[i]);
                        printf("%s   ",new_name[i]);
                        printf("%s   ",new_surname[i]);
                        printf("%s   ",new_birthday[i]);
                        printf("%s   ",new_email[i]);
                        printf("%s   ",new_department[i]);
                        l++;
                    }
                }
                printf("\nSearch completed. %d patient(s) are found...",l);
            }                   
        }
        
        else if (option == 3) //save new patient
        {   
            m = k;
            for (i = k; i < m + 1; i++)
            {   
                if (k == 0)
                {
                    new_id[i] = i + 1;
                }
                else{
                    for (y = 0; y < k; y++)
                    {
                        if (new_id[y]>= 1)
                        {
                            top_numb = new_id[y];
                        }
                    }
                    new_id[i] = top_numb + 1;
                }
                
                printf("\nEnter Name: ");
                scanf("%s",&new_name[i][0]);
                printf("\nEnter Surname: ");
                scanf("%s",&new_surname[i][0]);
                printf("\nEnter Birthday (dd/mm/yyyy): ");
                scanf("%s",&new_birthday[i][0]);
                printf("\nEnter E-Mail: ");
                scanf("%s",&new_email[i][0]);
                printf("\nEnter Department: ");
                scanf("%s",&new_department[i][0]);
                k++;
                printf("\n New patient has been recorded...\n\n");
                FILE *fp;
                fp = fopen("out.txt","w");
                for (i = 0; i < k; i++)
                {                       
                    
                    if (new_id[i] != -99)
                    {
                        fprintf(fp,"%d   %s   %s   %s   %s   %s   ",new_id[i], new_name[i], new_surname[i], new_birthday[i], new_email[i], new_department[i]);
                        fprintf(fp,"\n");
                    }
                }
                fclose (fp);
            }
        } /* bitti */
    }
}
