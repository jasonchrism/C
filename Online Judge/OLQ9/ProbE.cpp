#include <stdio.h>

void rec(int arr[], int limit, int index, int sum){
    if (index == limit){
        printf("%d\n", sum);
        return;    
    } else if (2 * index == limit){
        printf("%d\n", sum + arr[2 * index]);
        return;
    } else if (2 * index > limit){
        printf("%d\n", sum);
        return;
    }
    rec(arr, limit, 2 * index, sum + arr[2 * index]);
    rec(arr, limit, (2 * index) + 1, sum + arr[(2 * index) + 1]);
}

int main(){
    int cases;
    int size;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++){
        scanf("%d", &size);
        int value[size + 1];
        for (int j = 1; j <= size; j++){
            scanf("%d", &value[j]);
        }
        printf("Case #%d:\n", i);
        rec(value, size, 1, value[1]);
    }
}