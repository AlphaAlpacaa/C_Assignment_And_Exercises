#include <stdio.h> 
#include <stdlib.h> 
#include "matrix.h" 
#define DATA_LENGTH 8 
#define POLY_ORDER 3  
int main() {  int i, j;  double time[DATA_LENGTH] = {0,  3,  5,  9, 11, 14, 18, 20};  double pos[DATA_LENGTH] =  {0, 10, 24, 33, 36, 40, 44, 50};  double *A=malloc((POLY_ORDER+1)*(POLY_ORDER+1)*sizeof(double));  double *b=malloc((POLY_ORDER+1)*sizeof(double));  double *x, aVal;    for(i=0;i<(POLY_ORDER+1);i++)     for(j=0;j<(POLY_ORDER+1);j++)   *(A+(POLY_ORDER+1)*i+j)=VectorSum(VectorPow(time, DATA_LENGTH,i+j),DATA_LENGTH);    for(j=0;j<(POLY_ORDER+1);j++)     *(b+j)=DotProduct(VectorPow(time,DATA_LENGTH,j),pos,DATA_LENGTH);    // x=A^-1*b  x=Multiply(Inverse(A,POLY_ORDER+1),b,(POLY_ORDER+1),(POLY_ORDER+1),1);   free(A);  free(b);  
 printf("Best fit: x=");  for(i=0;i<(POLY_ORDER+1);i++)  {   aVal=*(x+POLY_ORDER-i);   if(aVal>0) printf("+");   printf("%.4lf*t^%d",aVal,POLY_ORDER-i);  }  free(x);   return 0; }
