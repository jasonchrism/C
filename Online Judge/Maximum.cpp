#include <stdio.h>

int main(){

    int input, a;
    int max, min;

    scanf("%d", &input);
    for (int i = 0; i < input; i++){
        scanf("%d", &a);
        int b;

        int max1 = -1000000;
        int max2 = -1000000;
        for (int j = 0; j < a; j++){
            scanf("%d", &b);
            if (b > max1){
                max2 = max1;
                max1 = b;
            } else if (b > max2){
                max2 = b;
            }      
        }
        printf("Case #%d: %d\n", i+1, max1 + max2);
    }


}