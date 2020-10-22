#include <stdio.h>
#include <stdlib.h>

int SetDimension();
int ** CreateArray (int, int);
void FillArray (int **, int, int);
void ShowArray (int **, int);
int ** MultiplyRows(int **, int **, int);
int ** SumColumns (int **, int **, int);

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
    ShowArray(firstArray, arrayDimension);
    
    secondArray = CreateArray(arrayDimension, second);
    FillArray(secondArray, arrayDimension, second);
    ShowArray(secondArray, arrayDimension);
    
    printf("paragraph A\n");
    resultArray = MultiplyRows(firstArray, secondArray, arrayDimension);
    ShowArray(resultArray, arrayDimension);
    
    printf("paragraph B\n");
    resultArray = SumColumns(resultArray, secondArray, arrayDimension);
    ShowArray(resultArray, arrayDimension);
    
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

void ShowArray (int ** arr, int size){
    int i, j;
    printf("Your array:\n");
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

int ** SumColumns(int ** arrOne, int ** arrTwo, int size){
    int * multiplyElements = MultiplyRowElements(arrTwo, size);
    int i, j;
    
    for (j = 0; j < size; j++){
        for(i = 0; i < size; i++){
           arrOne[i][j] += multiplyElements[j];
        }
    }
    free(multiplyElements);
    return arrOne;
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
        for(j = 0; j < size; j++){
            resultArr[i] *= arr[i][j];
        }
    }
    
    return resultArr;
}
