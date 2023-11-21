#include <stdio.h>
#include <string.h>

int main(){

    int cases;
    int shift;
    char input[1100] = {};

    FILE *filePointer;
    filePointer = fopen("testdata.in", "r");
    
    fscanf(filePointer, "%d", &cases);

    for (int i = 0; i < cases; i++){
    fscanf(filePointer, "%d", &shift);
    getc(filePointer);
    fscanf(filePointer, "%[^\n]", input);
        for (int j = 0; j < strlen(input); j++){
            if (input[j] != ' '){
                if (input[j] == '0'){
                input[j] = 'O';
            } else if (input[j] == '1'){
                input[j] = 'I';
            } else if (input[j] == '3'){
                input[j] = 'E';
            } else if (input[j] == '4'){
                input[j] = 'A';
            } else if (input[j] == '5'){
                input[j] = 'S';
            } else if (input[j] == '6'){
                input[j] = 'G';
            } else if (input[j] == '7'){
                input[j] = 'T';
            } else if (input[j] == '8'){
                input[j] = 'B';
            }
                if (input[j] - shift < 'A'){
                    input[j] = input[j] - shift + 26;
                } else {
                    input[j] = input[j] - shift;
                }
            }
        }
        printf("Case #%d: %s", i + 1, input);
        printf("\n");
    }
    fclose(filePointer);
}