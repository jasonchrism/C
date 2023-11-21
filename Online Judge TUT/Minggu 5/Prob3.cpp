#include <stdio.h>
#include <string.h>

int main(){

    int input;

    scanf("%d", &input);
    for (int i = 0; i < input; i++){
        char S[100000]={};
        int arr[255]={};
        int counter = 0;
        scanf("%s", S);
        for (int j = 0; j < strlen(S); j++){   
            if (arr[S[j]] == 0){
                counter++;
                arr[S[j]] = 1;
            }
        }
        if (counter % 2 == 1){
            printf("Case #%d: Unbreakable\n", i+1);
        } else {
            printf("Case #%d: Breakable\n", i+1);
        }
    }

}