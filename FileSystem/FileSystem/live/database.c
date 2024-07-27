#include "database.h"

int initDatabase()
{
	dbFile = fopen("database.txt", "a+");
	if(dbFile == NULL)
	{
		return -1;
	}
	readDatabase();
	return 0;
}

Customer* getCustomers()
{
	return customers;
}
int getCustomerIndex()
{
	return customerIndex;
}

int readDatabase()
{
	rewind(dbFile);
	int lineNumber = 0;
	while(!feof(dbFile))
	{
		if(lineNumber == 0)
		{
			fscanf(dbFile, "%d\n", &lastId);
		}else{
			int age;
			int id;
			char nameBuffer[50];
			char emailBuffer[50];
			char lineBuffer[200];
			//lineBuffer = fgets(lineBuffer,200,dbFile);
			int check = fscanf(dbFile, "%d %s %s %d", &id, nameBuffer, emailBuffer, &age);
			if(check == 4)
			{
				Customer customer = createCustomer(age, nameBuffer, emailBuffer);
				customerIndex++;
				customers[customerIndex] = customer;
			}
			
		}
		lineNumber++;
	}
	printf("Read customer count %d\n", customerIndex+1);
}
int updateDatabase()
{
	clearDatabase();

	rewind(dbFile);
	fprintf(dbFile, "%d\n", lastId);
	int i;

	for(i=0;i<customerIndex+1;i++)
	{
		Customer customer = customers[i];
		fprintf(dbFile, "%d  %s %s %d\n", customer.id, customer.name, customer.email, customer.age);
	}
}
int addCustomer(int age, char* name, char* email)
{
	Customer newCustomer = createCustomer(age, name, email);
	newCustomer.id = lastId;
	customerIndex++;
	lastId++;
	customers[customerIndex] = newCustomer;
	updateDatabase();
}
void clearDatabase()
{
	freopen("./database.txt",  "w+", dbFile);
}
void closeDatabase()
{
	fclose(dbFile);
}
