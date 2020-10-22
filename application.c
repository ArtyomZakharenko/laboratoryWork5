#include <stdio.h>
#include <stdlib.h>

int ** CreateArray (int *, int);
void FillArray (int **, int);
void ShowArray (int **, int, int);
int ** MultiplyRows(int **, int **, int, int);

int * SearchingMaxElementInRow(int **, int);

int main()
{
    int first = 1;
    int second = 2;
    
    int **firstArray = NULL;
    int **secondArray = NULL;
    int **resultArray = NULL;
    
    int firstArrayDimension, secondArrayDimension;
    
    firstArray = CreateArray(&firstArrayDimension, first);
    FillArray(firstArray, firstArrayDimension);
    
    secondArray = CreateArray(&secondArrayDimension, second);
    FillArray(secondArray, secondArrayDimension);
    
    ShowArray(firstArray, firstArrayDimension, first);
    ShowArray(secondArray, secondArrayDimension, second);
    
    resultArray = MultiplyRows(firstArray, secondArray, firstArrayDimension, secondArrayDimension);
    ShowArray(resultArray, firstArrayDimension, first);
    return 0;
}

int ** CreateArray (int * size, int number){
    int i;
    printf("Enter dimenshion of array %d: ", number);
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

void ShowArray (int ** arr, int size, int number){
    int i, j;
    printf("Your array %d:\n", number);
    for (i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}

int ** MultiplyRows (int ** arrOne, int ** arrTwo, int sizeOne, int sizeTwo){
    int * maxElements = SearchingMaxElementInRow(arrTwo, sizeTwo);
    int i,j;
    
    int ** resultArr = (int **)calloc(sizeOne, sizeof(int));
    for(i = 0; i < sizeOne; i++){
        resultArr[i] = (int *)calloc(sizeOne, sizeof(int));
    }
    
    for (i = 0; i < sizeOne; i++){
        for(j = 0; j < sizeOne; j++){
           resultArr[i][j] = arrOne[i][j] * maxElements[i];
        }
    }
    free(maxElements);
    return resultArr;
}

int * SearchingMaxElementInRow (int ** arr, int size){
    int i, j;
    int * resultArr = (int *)calloc(size, sizeof(int));
    for (i = 0; i < size; i++){
        resultArr[i] = arr[i][0];
    }
    
    for (i = 0; i < size; i++){
        for(j = 0; j < size; j++){
           if (resultArr[i] < arr[i][j]){
               resultArr[i] = arr[i][j];
           } 
        }
    }
    return resultArr;
}
