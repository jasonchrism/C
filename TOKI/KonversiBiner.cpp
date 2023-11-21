#include <stdio.h>

void biner(int num){
    if (num <= 0){
        return;
    }
    biner(num / 2);
    printf("%d", num % 2);
}

int main(){

    int num;
    scanf("%d", &num);
    biner(num);

}