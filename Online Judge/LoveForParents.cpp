#include <stdio.h>

int main(){

    int input,a,b;
    
    scanf("%d", &input);
    int price[input];
    for (int i = 0; i < input; i++){
        scanf("%d", &price[i]);
    }

    int change;
    scanf("%d", &change);
    for (int j = 0; j < change; j++){
        scanf("%d%d", &a,&b);
        price[a-1] = b;
        printf("Case #%d:", j+1);
        for (int k = 0; k < input; k++){
            if (k < input){
            printf(" ");
            }
            printf("%d", price[k]);
        }
        printf("\n");
    }
}