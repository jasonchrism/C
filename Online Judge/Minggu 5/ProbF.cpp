#include <stdio.h>

int main(){

    int input;
    int cases;
    int need[100000];
    int own[100000];

    scanf("%d", &input);

    for (int i = 0; i < input; i++){
        scanf("%d", &cases);
        for (int j = 0; j < cases; j++){
            scanf("%d", &need[j]);
        }
        for (int k = 0; k < cases; k++){
            scanf("%d", &own[k]);
        }
        printf("Case #%d:", i+1);
    for (int m = 0; m < cases; m++){
        printf(" %d", need[m] - own[m]);
    }
    printf("\n");
    }
}