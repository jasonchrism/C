#include <stdio.h>

void fortoki(){
    int cases;
    int value[1000];
    int result = 0;
    
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        scanf("%d", &value[i]);
        result = result + value[i];
    }
    printf("%d", result);
}

void whiletoki(){
    char input[100];
    while (scanf("%s", input) != EOF) {
        printf("%s", input);
        printf("\n");
    }

}

void whilePencacah(){
    int num;
    int res = 0;
    while (scanf("%d", &num) != EOF){
        res = num + res;
    }
        printf("%d", res);
}

void duaPangkat(){
    int num;
    scanf("%d", &num);
    while (num % 2 == 0){
        num = num / 2;
    }
    if (num == 1){
        printf("ya");
    } else {
        printf("bukan");
    }
}

void faktorBilangan(){
    int num;
    scanf("%d", &num);
    for (int i = num; i > 0; i--){
        if (num % i == 0){
            printf("%d\n", i);
        }
    }
}

void bilBesarKecil(){
    int cases;
    int num[100];
    int max = 99999, min = -99999;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        scanf("%d", &num[i]);
        if (num[i] > min){
            min = num[i];
        }
        if (num[i] < max){
            max = num[i];
        }
    }
        printf("%d %d", min, max);
}

void statistikaSederhana(){
    int cases;
    int num;
    int max = -100001;
    int min = 100001;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        scanf("%d", &num);
        if (num > max){
            max = num;
        }
        if (num < min){
            min = num;
        }
    }
    printf("%d %d", max, min);
}

int main(){

    statistikaSederhana();

}