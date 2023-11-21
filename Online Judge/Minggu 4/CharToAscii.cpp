#include <stdio.h>
#include <string.h>

int main(){

    int input;
    char kasus[1001];

    scanf("%d", &input);
    for (int i = 0; i < input; i++){
        scanf("%s", kasus);
        printf("Case %d: ", i+1);
        for (int k = 0; k < strlen(kasus); k++){
            printf("%d", kasus[k]);
         if (k != strlen(kasus) - 1){
            printf("-");
            }
        }
    printf("\n");
    }

}