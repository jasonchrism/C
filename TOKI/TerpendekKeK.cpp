#include <stdio.h>

int partition(int value[], int low, int high){
    int i = low - 1;
    int j = low;
    int pivot = value[high];
    while (j < high){
        if (value[j] < pivot){
            i++;
            int temp = value[j];
            value[j] = value[i];
            value[i] = temp;
        }
        j++;
    }
    value[high] = value[i+1];
    value[i+1] = pivot;
    return (i+1);
}

void quickSort(int value[], int low, int high){
    if (low < high){
        int pos = partition(value, low, high);
        quickSort(value, low, pos - 1);
        quickSort(value, pos + 1, high);
    }
}

int main(){

    int cases, ask;
    scanf("%d %d", &cases, &ask);
    int value[cases] = {};
    for (int i = 1; i <= cases; i++){
        scanf("%d", &value[i]);
    }
    quickSort(value, 0, cases - 1);
    printf("%d\n", value[ask-1]);
}