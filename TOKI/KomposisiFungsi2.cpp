#include <stdio.h>
#include <math.h>

int compositionFunc(int A, int B, int K, int x){
    if (K == 0){
        return x;
    }
    return abs(A * compositionFunc(A, B, K - 1, x) + B);
}

int main(){

    int A, B, K, x;
    scanf("%d%d%d%d", &A, &B, &K, &x);
    printf("%d", compositionFunc(A, B, K, x));

}