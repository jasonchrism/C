#include <stdio.h>

void balikDaftar(){
    int num[100] = {}, x = 0;
    while (scanf("%d", &num[x]) != EOF){
        x++;
    }
    for (int i = x - 1; i >= 0; i--){
        printf("%d\n", num[i]);
    }
}

void modusTerbesar(){
    int cases;
    scanf("%d", &cases);
    int num[1001] = {};
    int temp, modus, count = 0;
    for (int i = 0; i < cases; i++){
        scanf("%d", &temp);
        num[temp]++;
    }
    for (int i = 0; i < 1001; i++){
        if (num[i] >= count){
            count = num[i];
            modus = i;
        }
    }
    printf("%d\n", modus);
}

void rotasiMatriks(){

    int row, column;
    int value[100][100] = {};
    scanf("%d %d", &row, &column);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            scanf("%d", &value[i][j]);
        }
    }
    for (int i = 0; i < column; i++){
        for (int j = 0; j < row; j++){
            printf("%d ", value[row-1][i]);
            row--;
        }
        printf("\n");
    }

}

int main(){

    rotasiMatriks();

}