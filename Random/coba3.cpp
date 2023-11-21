#include <stdio.h>
#include <string.h>

int main(){

    char name[100];
    char name1[100];
    scanf("%[^\n]\n", name); 
    scanf("%s", name1); getchar();

    strcat(name, name1);
    printf("%s", name);

}