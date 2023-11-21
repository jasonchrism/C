#include <stdio.h>

int main(){

    int n;
    int a = 0;

    scanf("%d", &n);

    if ((n >= 1) && (n <= 100)){
        for (int i = 2; i < n; i++){
            if (n % i == 0){
                n = 1;
                break;
            }
        }
        if ((n == 0) && (n < 7) && (n > 1)){
            printf("YES");
        } else {
            printf("NO");
        }
    }


}