#ifndef DATABASE_H
#define DATABASE_H

#include "customer.h"


static FILE* dbFile;
static Customer customers[100];
static int customerIndex = -1;
static int lastId = 0;

int initDatabase();
Customer* getCustomers();
void clearDatabase();
void updateDatabase();
void closeDatabase();

//CRUD
int getCustomerNumber();
int readCustomers();
int addCustomer(int age, char* name, char* email);
int updateCustomer(Customer customer);
int deleteCustomer(Customer customer);

#endif
