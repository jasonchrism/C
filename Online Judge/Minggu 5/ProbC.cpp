#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char input[10000];
    scanf("%[^\n]", input);

    for (int i = 0; i < strlen(input); i++){
        input[i] = tolower(input[i]);
        if (input [i] == '1'){
            input [i] = 'i';
        }
        if (input [i] == '2'){
            input [i] = 'r';
        }
        if (input [i] == '3'){
            input [i] = 'e';
        }
        if (input [i] == '4'){
            input [i] = 'a';
        }
        if (input [i] == '5'){
            input [i] = 's';
        }
        if (input [i] == '6'){
            input [i] = 'g';
        }
        if (input [i] == '7'){
            input [i] = 't';
        }
        if (input [i] == '8'){
            input [i] = 'b';
        }
        if (input [i] == '9'){
            input [i] = 'p';
        }
        if (input [i] == '0'){
            input [i] = 'o';
        }
    }
        printf("%s\n", input);

}