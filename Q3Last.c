#include <stdio.h>


void swapHalves(int *arr, int size){
    if(size%2 == 0){
        int i, k = 0;
        int B[size]; 
        k = size / 2;
        for (i = 0; i < size; i++){
            if(i >= k){
                arr[i] = B[i - k];
            }
            else if(i != k){
                B[i] = arr[i];
                arr[i] = arr[i + k];
            }
            printf("%d ",arr[i]);
        }
    }

    else{
        int i, k = 0;
        int B[size]; 
        k = (size + 1) / 2;
        for (i = 0; i < size; i++){
            if(i != k){
                B[i] = arr[i];
                arr[i] = arr[i + k];
            }

            if(i == k - 1){
                arr[i] = B[k - 1];
            }
            else if(i >= k){
                arr[i] = B[i - k];
            }

            printf("%d ",arr[i]);
        }
    }
}

int main(){
    int size;
    scanf("%d", &size);
    int A[size];    
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &A[i]);
    }
    swapHalves(A,size);
    return 0;
}
