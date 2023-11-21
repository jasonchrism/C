#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(0));
    printf("%d\n", rand()%10 + 5);

    // char name[6];
    // int a = rand()%10;
    // int b = rand()%10;
    // scanf("%d%d", &a, &b);
    // sprintf(name, "Jason%d%d", a,b);
    // printf("%s\n", name);


}