#include <stdio.h>
#include <stdlib.h>

int SetDimension();
int ** CreateArray (int, int);
void FillArray (int **, int, int);
void ShowArray (int **, int, int);
int ** MultiplyRows(int **, int **, int);


int * SearchingMaxElementInRow(int **, int);
int * MultiplyRowElements (int **, int);

int main()
{
    int first = 1;
    int second = 2;
    
    int **firstArray = NULL;
    int **secondArray = NULL;
    int **resultArray = NULL;
    
    int arrayDimension = SetDimension();
    
    firstArray = CreateArray(arrayDimension, first);
    FillArray(firstArray, arrayDimension, first);
    
    secondArray = CreateArray(arrayDimension, second);
    FillArray(secondArray, arrayDimension, second);
    
    ShowArray(firstArray, arrayDimension, first);
    ShowArray(secondArray, arrayDimension, second);
    
    resultArray = MultiplyRows(firstArray, secondArray, arrayDimension);
    
    return 0;
}

int SetDimension(){
    int size;
    printf("Enter dimenshion of array: ");
    scanf("%d", &size);
    printf("\n");
    
    return size;
}

int ** CreateArray (int size, int number){
    int i;
    int **arr = (int **)calloc(size, sizeof(int *));
    for (i = 0; i < size; i++){
        arr[i] = (int*)calloc(size, sizeof(int));
    }
    
    return arr;
}

void FillArray(int ** arr, int size, int number){
    int i, j;
    printf("Fill array %d:\n", number);
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
    printf("\n");
}

int ** MultiplyRows (int ** arrOne, int ** arrTwo, int size){
    int * maxElements = SearchingMaxElementInRow(arrTwo, size);
    int i,j;
    
    int ** resultArr = (int **)calloc(size, sizeof(int));
    for(i = 0; i < size; i++){
        resultArr[i] = (int *)calloc(size, sizeof(int));
    }
    
    for (i = 0; i < size; i++){
        for(j = 0; j < size; j++){
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

int * MultiplyRowElements (int ** arr, int size){
    int i, j;
    int * resultArr = (int *)calloc(size, sizeof(int));
    
    for (i = 0; i < size; i++){
        resultArr[i] = 1;
    }
    
    for (i = 0; i < size; i++){
        printf("%d ", resultArr[i]);
    }
    
    for (i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            resultArr[i] *= arr[i][j];
        }
    }
    
    return resultArr;
}
