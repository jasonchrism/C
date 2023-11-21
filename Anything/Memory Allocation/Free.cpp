#include <stdio.h>
#include <stdlib.h>

int main(){

    int *arr, n;
    printf("Input total elements : ");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        printf("Input element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Reversed : ");
    for (int i = n-1; i >= 0; i--){
        printf("%d ", arr[i]);
    }
    free(arr);

}