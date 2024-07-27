#include <stdio.h>


void swapHalves(int arr, int size){
    int i, k;
    int A[i]; 
    k = size / 2 + 2;
    for (i = 0; i < size; i++){
        A[i] = A[i + k];
    }
}
void swapHalves2(int arr, int size){
    int i, k;
    int A[i]; 
    k = (size + 1) / 2 + 2;
    for (i = 0; i < size; i++){
        A[i] = A[i + k];
    }
}

