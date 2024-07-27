#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int getIndexOfChar(const char* str, char c);
void getKeyVal(const char* pair, char* key, char* val);
void parseUrl(const char* url, char** keys, char** values);
char* getElementByKey(char** keys, char** vals, char* key);

int main()
{
	char* url = "www.asda.com?key1=val1&key2=val2";
	char* keys[50] = {NULL}; //Array of NULL
	char* values[50] = {NULL}; //Array of NULL
	
	char* username = "doruk";
	char* password = "12345";
	
	parseUrl(url, keys, values);
	int i;
	while(keys[i] != NULL)
	{
		printf("Key:%s  Val:%s\n", keys[i], values[i]);
		i++;
	}
	printf("%s\n", getElementByKey(keys, values, "key1"));
}

int getIndexOfChar(const char* str, char c)
{
		//Get the location
		char* loc = strchr(str, c);
		if(loc!=NULL)
		{
			return (int)(loc-str);
		}
		else
		{
			return -1;
		}
		
}
void getKeyVal(const char* pair, char* key, char* val)
{
	int index = getIndexOfChar(pair, '=');
	if(index != -1)
	{
		strncpy(key,pair,index);
		strcpy(val,pair+index+1);
	}
}
void parseUrl(const char* url, char** keys, char** values)
{
	if(strchr(url, '?')!=NULL)
	{
		int index = getIndexOfChar(url, '?');
		char* arguments[50];
		strcpy(arguments, url+index+1);
		
		//Seperate by '&'
		char* arg = strtok(arguments, "&");  //'&' yazýlýrsa hata oluþur çünkü '&' bir pointer deðil
		
		if(arg != NULL)
		{
			int counter = 0;
			while(arg != NULL)
			{
				keys[counter]=malloc(sizeof(char)*20);  //Allocate mem
				values[counter]=malloc(sizeof(char)*20);  //Allocate mem
				
				//Soru: Neden malloc a ihtiyacýmýz var?
				getKeyVal(arg, keys[counter], values[counter]);
				arg = strtok(NULL, "&");
				counter++;
			}
		}
		else
		{
			getKeyVal(arguments, keys[0], values[0]);
		}
		
	}
	else
	{
		printf("Url doesn't have any arguments\n");
	}
}
char* getElementByKey(char** keys, char** vals, char* key)
{
	int counter = 0;
	while(keys[counter] != NULL)
	{
		if(!strcmp(keys[counter], key))
		{
			return vals[counter];
		}
		counter++;
	}
	return NULL;
}

