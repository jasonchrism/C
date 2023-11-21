#include <stdio.h>

void mountain(int num){
    if (num > 0){
        mountain(num - 1);
        for (int i = 0; i < num; i++){
            printf("*");
        }
        printf("\n");
        mountain(num - 1);
    }
}

int main(){

    int num;
    scanf("%d", &num);
    mountain(num);

}