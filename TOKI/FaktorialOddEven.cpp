#include <stdio.h>

int factOddEven(int n){
    if (n == 0){
        return 1;
    }
    if (n % 2 == 0){
        return factOddEven(n-1) * (n / 2);
    } else {
        return factOddEven(n-1) * n;
    }
}

int main(){

    int num;
    scanf("%d", &num);
    printf("%d\n", factOddEven(num));

}