#include <stdio.h>

int partition(long long int value[], int low, int high){
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

void quickSort(long long int value[], int low, int high){
    if (low < high){
        long long int pos  = partition(value, low, high);
        quickSort(value, pos + 1, high);
    }
}

int main(){

    long long int cases;
    scanf("%lld", &cases);
    long long int value[cases]= {};
    for (int i = 0; i < cases; i++){
        scanf("%lld", &value[i]);
    }
    // quickSort(value, 0, cases - 1);
    long long int test;
    long long int left, right;
    scanf("%lld", &test);
    long long int count = 0;
    for (int i = 0; i < test; i++){
        scanf("%lld %lld", &left, &right);
        for (int j = 0; j < cases; j++){
            if (value[j] > left && value[j] <= right){
                count++;
            }
        }
        printf("%d\n", count);
        count = 0;
    }

}