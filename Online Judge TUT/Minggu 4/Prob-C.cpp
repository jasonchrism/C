#include <stdio.h>

int main(){

    int input;
    int cases;
    long long int data[100][100] = {};
    long long int sum = 0;

    scanf("%d", &input);

    for (int i = 0; i < input; i++){
        scanf("%d", &cases);
        for (int j = 0; j < cases; j++){
            for (int k = 0; k < cases; k++){
                scanf("%lld", &data[j][k]);
            }
        }
        printf("Case #%d:", i + 1);

        for (int i = 0; i < cases; i++){
            for (int j = 0; j < cases; j++){
                sum = sum + data[j][i];
            }
            printf(" %lld", sum);
            sum = 0;
        }
        printf("\n");
    }

}