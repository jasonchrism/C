#include <stdio.h>

int main(){

    int cases;
    int sum;
    int result = 0;
    int counter;
    int a1;
    int b1;
    long long int a;
    long long int b;
    int multiply = 1;

    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        scanf("%lld%lld", &a, &b);
        while (a || b){
            a1 = a % 10;
            b1 = b % 10;
            sum = (a1 + b1) % 10;
            result = sum * multiply + result;           
            multiply *= 10;
            a = a / 10;
            b = b / 10; 
        }
        printf("%d", result);
        printf("\n");3
    }


}