#include "database.h"

int initDatabase()
{
	dbFile = fopen("./database.txt", "a+");
	if(dbFile == NULL)
	{
		return -1;
	}
	readCustomers();
	printf("Ends %d\n", customerIndex);
	return 0;
}

void clearDatabase()
{
	freopen("./database.txt",  "w+", dbFile);
}
void closeDatabase()
{
	fclose(dbFile);
}

Customer* getCustomers()
{
	return customers;
}
int getCustomerNumber()
{
	return customerIndex;
}
int readCustomers()
{
	//First line is the last id
	rewind(dbFile);
	int lineNumber = 0;

	while(!feof(dbFile))
	{	

		if(lineNumber == 0)
		{
			int check = fscanf(dbFile, "%d\n", &lastId); //that \n is needed
			if(check==0)
			{
				lastId = 0; //Couldn't read. Possivle empty file
			}
		}else{
		//	fgets(lineBuffer, 200, dbFile);
			int age;
			int id;
			char nameBuffer[50];
			char emailBuffer[50];
			int check = fscanf(dbFile, "%d %s %s %d", &id, nameBuffer, emailBuffer, &age);
			if(check == 4)
			{
				Customer customer = createCustomer(age, nameBuffer, emailBuffer);
				customerIndex++;
				//printf("Adding to %d\n", customerIndex);
				customers[customerIndex] = customer;
			}
		}
		lineNumber++;
	}
}
void updateDatabase()
{
	clearDatabase();
	rewind(dbFile);
	fprintf(dbFile, "%d\n", lastId);
	int i;
	for(i=0;i<customerIndex+1;i++)
	{

		Customer customer = customers[i];
		fprintf(dbFile, "%d %s %s %d\n", customer.id, customer.name, customer.email, customer.age);
	}
}
int addCustomer(int age, char* name, char* email)
{
	//Customer newCustomer = createCustomer(age, name, email);
	Customer newCustomer = createCustomer(age, name, email);
	newCustomer.id = lastId;
	lastId++;
	customerIndex++;
	printf("Adding to %d\n", customerIndex);
	customers[customerIndex] = newCustomer;
	updateDatabase();
}
int updateCustomer(Customer customer)
{
	//Update a customer's info and save it to the database
}
int deleteCustomer(Customer customer)
{
	//Delete a customer
}
