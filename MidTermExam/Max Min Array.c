#include<stdio.h>

double Maximum(double [ 9 ]);
double Minimum(double [ 9 ]);

int main()
{
    double numbers[ 9 ] = {  10,23,13,4,52,6,87,8,1 };
	double max, min;
	
	max = Maximum( numbers );
	min = Minimum( numbers );
	
	printf( "Maksimum: %f\n", max );
	printf( "Minimum: %f\n", min );
	

	return 0;
}

double Maximum(double array[9])
{
	int i, max;
	max = array[0];
	for( i = 1; i < 9; i++ ) {
		if( max < array[i] )
			max = array[i];
	}
	return max;
}

double Minimum(double array[9])
{
	int i, min;
	min = array[0];
	for( i = 1; i < 9; i++ ) {
		if( min > array[i] ) {
			min = array[i];
		}
	}
	return min;
}

