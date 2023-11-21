#include <stdio.h>
#include <math.h>

void Perkalian(){
    int n;
    scanf("%d", &n);
    int R = 1;
    int C = n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i * j == n){
                if (abs(R-C) > abs(i - j)){
                    R = i;
                    C = j;
                }
            }
        }
    }
    printf("%d %d", R, C);
}

void cekPrima(){

    int cases;
    int num;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++){
        scanf("%d", &num);

        bool prime = true;
        if (num == 1){
            prime = false;
        }

        int div = 2;
        while (div < num){
            if (num % div == 0){
                prime = false;
            }
            div++;
        }

        if (prime){
            printf("YA\n");
        } else {
            printf("BUKAN\n");
        }
    }

}

int main(){

    cekPrima();

}