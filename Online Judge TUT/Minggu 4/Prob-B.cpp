#include <stdio.h>

int main(){

    int input;
    int cases;
    long long int data[10000];
    long long int min[10000];
    int sum = 0;
    
    scanf("%d", &input);

    for (int i = 0; i < input; i++){
        scanf("%d", &cases);
        for (int j = 0; j < cases; j++){
            scanf("%lld", &data[j]);
        }

        for (int k = 0; k < cases; k++){
            scanf("%lld", &min[k]);    
        }

        for (int l = 0; l < cases; l++){
            if (data[l] < min[l]){
                sum++;
            }
        }
        printf("Case #%d: %d\n", i+1, sum);
        sum = 0;
    }

}