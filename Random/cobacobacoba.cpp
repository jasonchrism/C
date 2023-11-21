#include <stdio.h>

int main(){

    int input;
    int cases;
    long long int data[10000][10000];
    int sum = 0;

    scanf("%d", &input);

    for (int i = 0; i < input; i++){
        scanf("%d", &cases);
        for (int j = 0; j < cases; j++){
            for (int k = 0; k < cases; k++){
                scanf("%lld", &data[j][k]);
            }
        }

    for (int l = 0; l < cases; l++){
        for (int m = 0; m < cases; m++){
            sum = sum + data[l][m];
            }
            printf("%d", sum);
        }
    }

    return 0;
}