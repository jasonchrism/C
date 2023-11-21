#include "stdio.h"

int main(){

    int n;
    int arr[150] = {};

    scanf("%d", &n);
    int x;
    for(int i = 0; i < n * n; i++){
        scanf("%d", &x);
        arr[x]++;
    }
    int opt = 0;
        for(int k = 1; k <= n; k++){
            if(arr[k] < n)
                opt++;
        }
    printf("%d\n", opt);

}

/*  3
    1 = min 3 org
    2 = min 3 org
    3 = min 3 org
    utk dinyatakan full team
    */