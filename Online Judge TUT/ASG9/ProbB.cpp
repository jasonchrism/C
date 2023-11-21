#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int counter = 0;
int fib(int n){
    if (n == 0|| n == 1){
        counter++;
        return n;
    }
    counter++;
    return fib(n-2) + fib(n-1);
}

int main(){
    int cases;
    int n;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        counter = 0;
        scanf("%d", &n);
        fib(n);
        int count = counter;
        printf("Case #%d: %d\n", i + 1, count);
    }
}