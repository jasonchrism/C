#include <stdio.h>
#include <string.h>

int main(){

    int input;
    char message[1000];
    int num[1001];

    scanf("%d", &input);
    for (int i = 0; i < input; i++){
        scanf("%s", message);
        for (int j = 0; j < strlen(message); j++){
        if (message[j] >= 'A' && message[j] <= 'D'){
            num[j] = message[j] - 'A';
            message[j] = 'A';
        } else if (message[j] >= 'E' && message[j] <= 'H'){
            num[j] = message[j] - 'E';
            message[j] = 'E';
        } else if (message[j] >= 'I' && message[j] <= 'N'){
            num[j] = message[j] - 'I';
            message[j] = 'I';
        } else if (message[j] >= 'O' && message[j] <= 'T'){
            num[j] = message[j] - 'O';
            message[j] = 'O';
        } else if (message[j] >= 'U' && message[j] <= 'Z'){
            num[j] = message[j] - 'U';
            message[j] = 'U';
        }   
        }
        printf("Case #%d:\n", i + 1);
        printf("%s\n", message);
        for (int k = 0; k < strlen(message); k++){
            printf("%d", num[k]);
        }
        printf("\n");
    }
}
