#include <stdio.h>

int fib(int num){
    if (num <= 1){
        return num;
    } else {
        return fib(num - 1) + fib(num - 2);
    }  
}

int main(){
    int num;
    scanf("%d", &num);
    printf("%d", fib(num));
}