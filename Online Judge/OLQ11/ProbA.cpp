#include <stdio.h>

int doBinarySearch(int* arr, int N, int ask){
    int result = -1;
    int needToFind = ask;
    int leftIdx = 1;
    int rightIdx = N;

    while (leftIdx <= rightIdx){
        int midIdx = (leftIdx + rightIdx) / 2;
        if (arr[midIdx] < needToFind){
            leftIdx = midIdx + 1;
        } else {
            if (arr[midIdx] == needToFind){
            result = midIdx;
            } 
            rightIdx = midIdx - 1;
        } 
    }
    return result;
}

int main(){

    int N, M;
    scanf("%d %d", &N, &M);
    int arr[N] = {};
    for (int i = 1; i <= N; i++){
        scanf("%d", &arr[i]);
    }
    int ask;
    for (int i = 0; i < M; i++){
        scanf("%d", &ask);
        int result = doBinarySearch(arr, N, ask);
        printf("%d\n", result);
    }
}