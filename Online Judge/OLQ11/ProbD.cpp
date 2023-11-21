#include<stdio.h>

int partition(long long int arr[], int low, int high){    
    int pivot = arr[high];
    int i = low - 1;
    int j = low;

    while (j < high){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }

        j++;
    }
    arr[high] = arr[i+1];
    arr[i+1] = pivot;
    return (i+1);
}

void quickSort(long long int arr[], int low, int high){

    if (low < high){
        int pos = partition(arr, low, high);
        quickSort(arr, low, pos-1);
        quickSort(arr, pos, high);
    }

}

int main(){
    int cases;
    scanf("%d", &cases);

    for (int i = 0; i < cases; i++){
        long long int arr[30] = {};
        long long int sum = 0;

        for (int j = 0; j < 25; j++){
           scanf("%lld", &arr[j]);
           sum+=arr[j];
        }  
        quickSort(arr, 0, 24);

        long long int A, B, C, D, E;
        A = (arr[0] / 2);
        E = (arr[24] / 2);
        B = (arr[1] - A);
        D = (arr[23] - E);
        C = (arr[4] - A);

        printf("Case #%d: %lld %lld %lld %lld %lld\n", i+  1, A, B, C, D, E);
    }
    
}