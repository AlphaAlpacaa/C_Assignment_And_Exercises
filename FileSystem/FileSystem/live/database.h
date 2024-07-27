#include <stdio.h>
#include <stdlib.h>
#include "customer.h"

static FILE* dbFile;
static int lastId = 0;
static int customerIndex = -1;
static Customer customers[100];

Customer* getCustomers();
int getCustomerIndex();
int initDatabase();
int readDatabase(); //Read operations
int updateDatabase(); //Write Operations
int addCustomer(int age, char* name, char* email);
void clearDatabase();
void closeDatabase();

void updateCustomer(Customer customer);
void deleteCustomer(Customer customer);
