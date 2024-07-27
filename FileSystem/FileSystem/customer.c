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
Customer* createCustomerDynamic(int age, char* name, char* email)
{
	Customer* customer = (Customer*) malloc(sizeof(Customer));
	customer->id = 0;
	customer->age = age;
	strcpy(customer->name, name);
	strcpy(customer->email, email);
	return customer;
}
void stringfyCustomer(Customer customer, char* buffer)
{
	sprintf(buffer,"%d %d %s %s",customer.id, customer.age, customer.name, customer.email);
}
