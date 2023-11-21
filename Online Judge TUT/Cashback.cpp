#include <stdio.h>

int main(){

    int input;


    scanf("%d", &input);
        int a[input], b[input];
    for (int i = 0; i < input; i++){
        scanf("%d%d", &a[i],&b[i]);
    }
    for (int j = 0; j < input; j++){
        if (a[j] > b[j]){
            printf("Case #%d: Go-Jo\n", j+1);
        } else {
            printf("Case #%d: Bi-Pay\n", j+1);
        }
    }



}