#include <stdio.h>

int main(){

    int a, b, c, x;

    printf("Masukkan nilai a : ");
    scanf("%d", &a);

    printf("Masukkan nilai b : ");
    scanf("%d", &b);

    printf("Masukkan nilai c : ");
    scanf("%d", &c);

    x = (((-b) +(2*c*c)) -(4*a*b)) / 2 * c;
    printf("Hasil dari x adalah : %d\n", x);

}