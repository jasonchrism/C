#include <stdio.h>

int main(){

    int p,q;
    int sum;

    scanf("%d%d", &p, &q);

    sum = ( p * p ) + (q * q) + 1;

    if (sum % 4 == 0){
        printf("%d", sum/4);
    } else {
        printf("-1");
    }


}