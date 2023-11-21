#include <stdio.h>
#include <string.h>

int main(){

    int input;
    char cases[1001];
   
    scanf("%d", &input);
    for (int i = 0; i < input; i++){
        scanf("%s", cases);
        printf("Case #%d : ", i+1);
        for (int j = strlen(cases)-1; j >= 0; j--){
            printf("%c", cases[j]);
        }
        printf("\n");
   }


}