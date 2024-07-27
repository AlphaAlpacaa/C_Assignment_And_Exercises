#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CustomerStruct Customer;
struct CustomerStruct
{
	int id;
	int age;
	char name[50];
	char email[50];
	int orders[10];
};

Customer createCustomer(int age, char* name, char* email);
Customer* createCustomerDynamic(int age, char* name, char* email);
void stringfyCustomer(Customer customer, char* buffer);

#endif
