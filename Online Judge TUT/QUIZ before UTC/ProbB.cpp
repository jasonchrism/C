#include <stdio.h>

int main(){

    int cases;
    int score;
    int bibi;
    int lili;
    int data[1000];

    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        scanf("%d", &score);
        for (int j = 0; j < score; j++){
            scanf("%d", &data[j]);
        }

        scanf("%d%d", &bibi, &lili);
        printf("Case #%d : ", i + 1);

        if (data[bibi-1] > data[lili-1]){
            printf("Bibi\n");
        } else if (data[bibi-1] < data[lili-1]){
            printf("Lili\n");
        } else {
            printf("Draw\n");
        }
    }

}