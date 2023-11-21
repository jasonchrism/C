#include <stdio.h>

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    int j = low;

    while (j < high){
        if (pivot >= arr[j]){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }
    arr[high] = arr[i+1];
    arr[i+1] = pivot;
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int pos = partition(arr, low, high);
        quickSort(arr, low, pos-1);
        quickSort(arr, pos, high);
    }
}

void printArray(int arr[], int arraySize){
    for (int i = 0; i < arraySize; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int numbers[] = {30, 20, 70, 90, 10, 40, 60, 50, 80};
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);

    printArray(numbers, arraySize);
    quickSort(numbers, 0, arraySize - 1);
    printArray(numbers, arraySize);
}