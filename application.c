
#include <stdio.h>
#include <stdlib.h>

int ** CreateArray (int *);

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
