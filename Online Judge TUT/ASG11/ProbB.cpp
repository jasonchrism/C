#include<stdio.h>

long long int arr[10000];

void quickSort(long long int arr[], int left, int right) {
    int i = left;
    int j = right;
    long long int temp;
    long long int pivot = arr[(left + right) / 2];
 
    while (i <= j){
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
 
    if (left < j){
        quickSort(arr, left, j);
    }
    if (i < right){
        quickSort(arr, i, right);
    }
}
int main(){
    int cases;
    scanf("%d", &cases);

    for (int i = 0; i < cases;i++){
    int height;
        scanf("%d", &height);
        for (int j = 0; j < height; j++){
            scanf("%lld", &arr[j]);
        }
        quickSort(arr, 0, height-1);
        long long int biggest = 0;
        for (int j = 1; j < height / 2;j++){
            if(j == 1){
                biggest = arr[j] - arr[j - 1];
            } else {
                if(arr[j] - arr[j - 1] > biggest)
                    biggest = arr[j] - arr[j - 1];
            }
        }
         for (int j = height / 2 + 1; j < height; j++){
            if(arr[j] - arr[j - 1] > biggest){
                biggest = arr[j] - arr[j - 1];
            }
        }
        printf("Case #%d: %lld\n", i + 1, biggest);
    }
}