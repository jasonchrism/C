#include <stdio.h>

int main(){

    int a,b;
    char c;

    scanf("%d %c %d", &a, &c, &b);

    if (c == '+'){
        printf("%d", a + b);
    } else if (c == '-'){
        printf("%d", a - b);
    } else if (c == '*'){
        printf("%d", a * b);
    } else if (c == '<'){
        if (a < b){
            printf("benar");
        } else {
            printf("salah");
        }
    } else if (c == '>'){
        if (a > b){
            printf("benar");
        } else {
            printf("salah");
        }
    } else if (c == '='){
        if (a == b){
            printf("benar");
        } else {
            printf("salah");
        }
    }



}