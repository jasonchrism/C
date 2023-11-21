#include <stdio.h>

int binarySearch(long long num, long long cases, long long total[]){
    int low = 0;
    int high = cases - 1;
    int mid;

    while (low < high){
        mid = (low + high) / 2;
        if (num <= total[mid]){
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    if (total[low] == num){
        return low;
    } else {
        return low - 1;
    }
}

int main(){

    int cases;
    long long int value[100000] = {};
    long long int total[100000] = {};
    scanf("%d", &cases);
    long long temp = 0;
    for (int i = 0; i < cases; i++){
        scanf("%lld", &value[i]);
        temp = temp + value[i];
        total[i] = temp;
    }
    int askNum;
    long long num;
    scanf("%d", &askNum);
    for (int i = 0; i < askNum; i++){
        scanf("%lld", &num);
        int result = binarySearch(num, cases, total);
        if (num < total[0]) result = -2; 
        if (num >= total[cases - 1]) result = cases - 1; 
        printf ("Case #%d: %d\n", i + 1, result + 1);
    }
}