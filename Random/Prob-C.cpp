#include <stdio.h>

int main(){

    int input;
    int cases;

    scanf("%d", &input);

    for (int i = 0; i < input; i++){
        long long data[100][100] = {};
        long long sum = 0;

        scanf("%d", &cases);
        for (int j = 0; j < cases; j++){
            for (int k = 0; k < cases; k++){
                scanf("%lld", &data[j][k]);
            }
        }
        printf("Case #%d: ", i + 1);

        for (int l = 0; l < cases; l++){
            for (int m = 0; m < cases; m++){
                sum = sum + data[m][l];
             }
                printf("%lld ", sum);
                sum = 0; 
         }
          
    }   
  return 0;
}