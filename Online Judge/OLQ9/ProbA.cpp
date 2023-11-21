#include <stdio.h>

int main(){
    int num1, num2;
    FILE *filePointer;
    filePointer = fopen("testdata.in", "r");
    fscanf(filePointer, "%d %d", &num1, &num2);
    printf("%d\n", num1 + num2);
    fclose(filePointer);
}