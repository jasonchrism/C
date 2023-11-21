#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product{
    char name[255];
    int price;
}productId;

int main(){
    //mode : 
    // - r : read
    // - w : write
    struct product productId[10];
    int lastIndex = 0;

    FILE *filePointer;
    filePointer = fopen("products.txt", "r");

    while (!feof(filePointer)){
        fscanf(filePointer, "%[^#]#%d\n", productId[lastIndex].name, &productId[lastIndex].price);
        printf("%s %d\n", productId[lastIndex].name, productId[lastIndex].price);
        lastIndex++;
    }
    fclose(filePointer);

    filePointer = fopen("products.txt", "w");
    strcpy(productId[lastIndex].name, "Sepatu");
    productId[lastIndex].price = 700000;
    lastIndex++;

    for (int i = 0; i < lastIndex; i++){
        fprintf(filePointer, "%s#%d\n", productId[i].name, productId[i].price);
    }
    fclose(filePointer);
}