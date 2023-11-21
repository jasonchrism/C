#include <stdio.h>

int main(){

    int x = 8;
    int *ptr;
    ptr = &x;

    printf("%d\t%d\n", ptr, *ptr);

    *ptr = 5;
    printf("%d\t%d\n", ptr,*ptr);

    int **ptr_ptr;
    ptr_ptr = &ptr;
    printf("%d\t%d\t%d\t%d\n", ptr_ptr, **ptr_ptr, ptr, *ptr);




}