#include <stdio.h>

int main(){

    int a,b,c;
    int A, B,C;

    scanf("%d%d", &a,&b);
    int index1[a][b];
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            scanf("%d", &index1[i][j]);
        }
    }

    scanf("%d", &c);
    for (int k = 0; k < c; k++){
            scanf("%d%d%d", &A, &B, &C);
            index1[A-1][B-1] = C;
    }

    for (int m = 0; m < a; m++){
        for (int n = 0; n < b; n++){
            printf("%d", index1[m][n]);
            if (n < b-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}