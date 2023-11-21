#include <stdio.h>

void printMenu(){
    printf("Menu\n");
    printf("=============\n");
    printf("1. Insert\n");
    printf("2. View\n");
}

int getValue(){
    return 10;
}

int doSum(int first, int second){
    return first + second;
}

int power(int initValue, int powValue){
    // return initValue * initValue;
    int result = 1;
    for (int i = 0; i < powValue; i++){
        result *= initValue;
    }
    return result;
}

void scanTwoNum(int *firstNum, int *secondNum){
    scanf("%d %d", firstNum, secondNum);
}

int factorial(int value){
    if (value == 0) return 1;
    return value * factorial(value - 1);
}

void doBubbleSort(){
    int arr[5] = {5, 2, 1, 4, 3};
    //Tandakan pembanding awal (looping)
    for (int i = 0; i < 5 - 1; i++){
        //Tandakan pembanding kedua (bagian kanannya)
        for (int j = i + 1; j < 5; j++){
            //Bandingkan apakah pembanding awal < pembanding kedua
            if(arr[i] < arr[j]) {}
            else {
                //Tukar nilainya
                //Tambah variabel ke 3
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//Pendukung untuk melakukan Insertion Sort
int sortedArrResult[5] = {};
void sort(int limit){
    //Pasang logic sorting dulu
    for (int i = 0; i< limit - 1; i++){
        if (sortedArrResult[i] <= sortedArrResult[limit]) {}
        else {
            int temp = sortedArrResult[i];
            sortedArrResult[i] = sortedArrResult[limit];
            sortedArrResult[limit] = temp;
        }
    }
}

void doInsertionSort(){
    int arr[5] = {5, 2, 1, 4, 3};
    for (int i = 0; i < 5; i++){
        sortedArrResult[i] = arr[i];
        sort(i);
    }
    for (int i = 0; i < 5 ; i++){
        printf("%d ", sortedArrResult[i]);
    }
    printf("\n");
}

void doSelectionSort(){
    int arr[5] = {5, 2, 1, 4, 3};
    for (int i = 0; i < 5 ; i++){
        int idxMin = -1;
        for (int j = i; j < 5; j++){
            if (j == i) idxMin = j;
            else if (arr[j] < arr[idxMin]) idxMin = j;
        }
        if (idxMin == 1) {}
        else {
            int temp = arr[i];
            arr[i] = arr[idxMin];
            arr[idxMin] = temp;
        }
    }
    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
}

int main(){

    // printMenu();

    // int returnedValue = getValue();
    // printf("%d\n", returnedValue);

    // int sumResult = doSum(2, 8);
    // printf("%d\n", sumResult);

    // int powResult = power(5, 3);
    // printf("%d\n", powResult);

    // int firstNum, secondNum;
    // scanTwoNum(&firstNum, &secondNum);
    // printf("%d %d\n", firstNum, secondNum);

    // int factorialResult = factorial(5);
    // printf("%d\n", factorialResult);

    doBubbleSort();
    doInsertionSort();
    doSelectionSort();

    return 0;
}