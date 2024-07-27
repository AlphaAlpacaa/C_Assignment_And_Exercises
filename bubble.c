#include <stdio.h>


void swap(int *a, int *b);
void bubble(int sorted[], int size, int (*compare)(int num1, int num2));
int ascend(int element1, int element2);
int descend(int element1, int element2);

int main()
{
	int arr[5]= {32, 23, 54, 1, 8}; //{23, 32, 1, 54, 8, 54}
	bubble(arr, 5, descend);
	int i = 0;
	for(i=0;i<5;i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;	
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble(int sorted[], int size, int (*compare)(int num1, int num2))
{
	int i;
	int j;
	for(i=1;i<size;i++){
		for(j=1;j<size;j++)
		{
			if(compare(sorted[j-1], sorted[j]))
			{
				swap(&sorted[j-1], &sorted[j]);
			}
		}
	}	
}
int ascend(int element1, int element2)
{
	if(element1>element2)
	{
		//Element 1 is bigger than element 2, it requires a swap
		return 1;
	}
	else
	{
		return 0;
	}
}
int descend(int element1, int element2)
{
	if(element1<element2)
	{
		//Element 2 is bigger than element 1, it requires a swap
		return 1;
	}
	else
	{
		return 0;
	}
}

