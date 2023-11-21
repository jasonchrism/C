#include <stdio.h>

int main(){

    char a[20], b[20], c[20];
    for (int i = 0; i < 2; i++){
        scanf("%s%s%s", a,b,c);
        printf("%sszs %sszs %sszs\n", a, b, c);
    }
}