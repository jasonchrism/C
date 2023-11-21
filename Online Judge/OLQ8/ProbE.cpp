#include <stdio.h>
#include <string.h>

char num[10000000] = {};

int main(){

   int cases;
   int temp;
   int result = 0;
   scanf("%d", &cases);
   for (int i = 0; i < cases; i++){
    scanf("%s", num); getchar();
    for (int j = strlen(num) - 1 ; j >= 0; j--){
        temp = num[j] - 48;
        if (j % 2 == 0){
            result = result + temp;
        } else {
            result = result - temp;
        }
    }
    if (result % 11 == 0){
        printf("Case #%d: Yeah\n", i + 1);
        result = 0;
    } else {
        printf("Case #%d: Nah\n", i + 1);
        result = 0;
    }
   }

}