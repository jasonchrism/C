#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int input;
    scanf("%d", &input);
    for (int i = 0; i < input; i++){
        char S[1000]={};
        scanf("%s", S);
        for (int j = 0; j < strlen(S); j++){
            if (islower(S[j])){
                S[j] = toupper(S[j]);
            } else if (isupper(S[j])){
                S[j] = tolower(S[j]);
            }
        }   
        printf("Case #%d: ", i + 1);
        for (int i = strlen(S)-1; i >= 0; i--){
        printf("%c", S[i]);
        }
        printf("\n");
    }

}