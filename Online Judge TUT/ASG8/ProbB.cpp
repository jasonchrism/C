#include <stdio.h>

int main(){

    int cases;
    int N;
    int X, Y;
    int temp = 0;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        scanf("%d %d %d", &N, &X, &Y);
        for (int j = 0; j < N; j++){
            temp = Y - X; //1
            X = Y; //2
            Y = temp; //1
        }
        printf("Case #%d: %d\n", i + 1, X);
    }

}
