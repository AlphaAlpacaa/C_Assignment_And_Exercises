#include <stdio.h>
#include <string.h>
#include "customer.h"
#include "database.h"

int main()
{
	if(initDatabase() == -1)
	{
		return -1;
	}
	int customerIndex = getCustomerIndex();
	printf("Read customer count from main %d\n", customerIndex+1);
	Customer* customers = getCustomers();
	Customer customer = customers[1];
	char buffer[200];
	stringfyCustomer(customer, buffer);
	printf(buffer);
	return 0;
	closeDatabase();
}
