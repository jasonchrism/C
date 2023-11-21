#include <stdio.h>

int main(){

    int input;
    int cases;
    int data[10000][10000];
    int sum = 0;

    scanf("%d", &input);

    for (int i = 0; i < input; i++){
        scanf("%d", &cases);
        for (int j = 0; j < cases; j++){
            for (int k = 0; k < cases; k++){
                scanf("%d", &data[j][k]);
            }
        }
    }

    for (int i = 0; i < cases; i++){
        for (int j = 0; j < cases; j++){
            sum = sum + data[i][j];
        }
        printf("%d", sum);
    }

    return 0;
}