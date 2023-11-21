#include <stdio.h>

int main(){

    int cases;
    scanf("%d", &cases);
    long long int N, M;
    long long int count = 0;
    for (int i = 0; i < cases; i++){
        scanf("%lld%lld", &N, &M);
        long long int value[N] = {};
        for (int j = 0; j < N; j++){
            scanf("%lld", &value[j]);
        }
        long long int max = 0;
        for (int j = 0; j < N; j++){
            long long int result = 0;
            count = 0;
            for (int k = j; k < N; k++){ //1 2 3 4 5
                if (result + value[k] <= M){
                    result = result + value[k];
                    count++;
                    if (count > max) max = count;
                } else {
                    break;
                }
            }
        }
        if (max == 0){
            printf("Case #%d: -1\n", i + 1);
        } else {
        printf ("Case #%d: %d\n", i + 1, max);
        }
    }
}