#include <stdio.h>
#include <math.h>

int cases;
int value[1000000];

int min(int first, int second){
    return (first > second) ? second : first;
}

int findMinimal(int arr[], int n, int calculateTemp, int totalSum){
    if(n == 0){
        return abs((totalSum - calculateTemp) - calculateTemp);
    }
    return min(findMinimal(arr, n - 1, calculateTemp + arr[n-1], totalSum), findMinimal(arr, n - 1, calculateTemp, totalSum));
}

int findMin(int arr[], int length){
    int totalSum = 0;
    for(int i = 0; i < length; i++){
        totalSum = totalSum + arr[i];
    }
    return findMinimal(arr, length, 0, totalSum);
}


int main(){

    int length;
    FILE* fp = fopen("testdataC.in", "r");
    while (!feof(fp)){
        fscanf(fp, "%d", &cases); getchar();
        for (int i = 0; i < cases; i++){
            fscanf(fp, "%d", &length); getchar();
            for (int j = 0; j < length; j++){
                fscanf(fp, "%d", &value[j]);
            }
            printf("Case#%d: %d\n", i + 1, findMin(value, length));
        }
    }

}