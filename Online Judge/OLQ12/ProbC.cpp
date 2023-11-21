#include <stdio.h>

int equation(int M, int N){
    if (M == 0 || N == 0){
        return 1;
    }
    return equation(M-1, N-1) + equation(M-1, N) + equation(M, N-1);
}

int main(){
    int M, N;
    scanf("%d %d", &M, &N);
    int result = equation(M,N);
    printf("%d\n", result);
}