#include <stdio.h>

int fib(int n){
    if (n <= 1) return n;
    return fib(n-1) + fib(n - 2);
}

int main(){

    int n;
    scanf("%d", &n);
    printf("Hasil dari fibonacci %d adalah %d", n, fib(n));

}