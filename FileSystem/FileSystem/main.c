#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"
#include "database.h"

extern int lastId;

int main()
{
	initDatabase();
	//clearDatabase();
	addCustomer(38, "Ali", "asdasd");
	addCustomer(39, "Ali", "asdasd");
	addCustomer(40, "Ali", "asdasd");
	addCustomer(41, "Ali", "asdasd");
	addCustomer(42, "Ali", "asdasd");
	Customer* customers = getCustomers();
	for(int i=0;i<getCustomerNumber();i++)
	{
		Customer customer = customers[i];
		printf("Customer name %d \n", customer.id);
	}
	closeDatabase();
}
