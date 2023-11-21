#include <stdio.h>

int main(){

    int n;
    int value[100][100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &value[i][j]);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j == n - 1){
                printf("%d", value[j][i]);
            } else {
                printf("%d ", value[j][i]);
            }
        }
        printf("\n");
    }

}