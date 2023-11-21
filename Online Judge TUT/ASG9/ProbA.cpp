#include <stdio.h>

void rec(char x, char y, int pos){
    if (pos == 0){
        printf("%c", x);
        return;
    } else if (pos == 1){
        printf("%c", y);
        return;
    } else {
        rec(x, y, pos-1);
        rec(x, y, pos-2);
    }
}

int main(){

    int cases;
    scanf("%d", &cases);
    for (int t = 0 ; t < cases; t++){
        int pos;
        char a, b;
        scanf("%d %c %c", &pos, &a, &b); getchar();
        printf("Case #%d: ", t + 1);
        rec(a, b, pos);
        printf("\n");
    }
}