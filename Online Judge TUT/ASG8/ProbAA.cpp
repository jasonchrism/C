#include <stdio.h>

int main(){

    int n1, n2;
    int index;
    int temp = 0;

    scanf("%d %d", &n1, &n2);
    scanf("%d", &index);
    for (int i = 1; i < index; i++){
        temp = n1 + n2;
        n1 = n2;
        n2 = temp;
    }
        printf("%d\n", n2);

}