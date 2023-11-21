#include <stdio.h>
#include <ctype.h>

int main(){

    // char a = '5';
    // int b = 10;
    // printf("%d\n", isdigit(a));
    // printf("%d", isdigit(b));

    // char c;
    // c = 'b';
    // printf("%d\n", islower(c));
    // c = 'A';
    // printf("%d", islower(c));

    // char d;
    // d = 'A';
    // printf("%d\n", isupper(d));
    // d = 'e';
    // printf("%d", isupper(d));

    int input;
    int result;
    int counter = 0;
    scanf("%d", &input);
    while (input > 0){
        input = input / 10;
        counter++;
    }
    printf("%d", counter);
}