
#include <stdio.h>
#include <stdlib.h>

int ** CreateArray (int *);
void FillArray (int**, int );

int main()
{

    return 0;
}

int ** CreateArray (int * size){
    int i;
    printf("Enter dimenshion of array: ");
    scanf("%d", size);
    int **arr = (int **)calloc(*size, sizeof(int *));
    for (i = 0; i < *size; i++){
        arr[i] = (int*)calloc(*size, sizeof(int));
    }
    
    return arr;
}

void FillArray(int ** arr, int size){
    int i, j;
    printf("Fill array:\n");
    for (i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            printf("row %d, element %d: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }
}
