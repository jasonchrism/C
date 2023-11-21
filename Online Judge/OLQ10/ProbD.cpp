#include <stdio.h>

int main(){

    int cases;
    int result = 0;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        int linecol;
        scanf("%d", &linecol);
        int value[500][500] = {};
        for (int j = 0; j < linecol; j++){
            for (int k = 0; k < linecol; k++){
                scanf("%d", &value[j][k]);
            }
        }
        printf("Case #%d:", i + 1);
        for (int j = 0; j < linecol; j++){
            for (int k = 0; k < linecol; k++){
                result = result + value[k][j];
            }
            printf(" %d", result);
            result = 0;
        }
        printf("\n");
    }
}