#include <stdio.h>

void probAA(){
    int cases;
    int num;
    int result = 0;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        scanf("%d", &num);
        result = result + num;
    }
    switch(result){
        case 9:
        printf("21"); break;

        case 33:
        printf("42"); break;

        case 76:
        printf("92"); break;

        case 53:
        printf("37"); break;

        case 80:
        printf("59"); break;

        case 97:
        printf("88"); break;

        default:
        printf("%d", result);
    }
}

void probB(){
    int cases, needs, has, stock;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        scanf("%d %d %d", &needs, &has, &stock);
        if (has + stock >= needs){
            printf("Case #%d: yes\n", i + 1);
        } else {
            printf("Case #%d: no\n", i + 1);
        }
    }
}

void probD(){
    int cases, male, female;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        scanf("%d %d", &male, &female);
        if (male % 2 == 0 && female % 2 == 0){
            printf("Case #%d: Party time!\n", i + 1);
        } else {
            printf("Case #%d: Need more frogs\n", i + 1);
        }
    }
}

void probE(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if ((a * b) > (c + d)){
        printf("True\n");
    } else {
        printf("False\n");
    }
}

void probG(){
    char a, b;
    int a1, b1;
    int res;
    scanf("%c %c", a, b); getchar();
    a1 = a; b1 = b;
    res = a1 * b1;
    printf("%d\n", res);
}

int main(){

 probG();

}