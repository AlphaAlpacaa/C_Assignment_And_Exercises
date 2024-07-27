#include "customer.h"

Customer createCustomer(int age, char* name, char* email)
{
	Customer customer;
	customer.id = 0;
	customer.age = age;
	strcpy(customer.name, name);
	strcpy(customer.email, email);
	return customer;	
}

void stringfyCustomer(Customer customer, char* buffer)
{
	printf("Name %s\n", customer.name);
	sprintf(buffer,"%d %d %s %s",customer.id, customer.age, customer.name, customer.email);
}

