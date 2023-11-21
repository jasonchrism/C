#include <stdio.h>

void breakContinueExit(){
    int num;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++){
        if (i % 10 == 0){
            continue;
        } else if (i == 42){
            printf("ERROR");
            break;
        } else {
            printf("%d\n", i);
        }
    }
}

void PolaII(){
    int input;
    scanf("%d", &input);
    for (int i = 0; i < input; i++){
        for (int j = 0; j < input; j++){
            if (j < input - i - 1){
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

void PolaIII(){
    int num;
    int count = -1;
    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        for (int j = 0; j <= i; j++){
            if (count < 9) count++;
            else count = 0;
            printf("%d", count);
        }
        printf("\n");
    }
}

int main(){

    PolaIII();

}