#include <stdio.h>

int main(){

    int input,temp;
    int index[1000], index1[1000];

    scanf("%d", &input);

    for (int i = 0; i < input; i++){
        scanf("%d", &index[i]);
    }

    for (int l = 0; l < input; l++){
        temp = index[l];
        scanf("%d", &index1[temp]);
    }

    for (int j = 0; j < input; j++){
        printf("%d", index1[j]);
        if (j < input-1){
            printf(" ");
        }
    }
    printf("\n");

}