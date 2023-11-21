#include <stdio.h>

void print(){
    static int num = 0;
    printf("Count = %d\n", num++);
}

int main(){
    for (int i = 0; i < 5; i++) print();
    for (int i = 0; i < 5; i++) print();
}

