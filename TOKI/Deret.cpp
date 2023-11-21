#include <stdio.h>

int main (){

    int start;
    int cases;
    int selisih;
    int j = 0;

    scanf("%d%d%d", &start, &cases, &selisih);

    for (int i = start; j < cases; i += selisih){
        printf("%d\n", i);
        j++;
    }



}