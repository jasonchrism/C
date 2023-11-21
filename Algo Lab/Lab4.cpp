#include <stdio.h>

int main(){

    int input, price;
    char name[100];

    printf("My Wishlist\n");
    puts("====================================");
    puts("| Item Name\t| Item Price|");
    puts(" Need you to feel it :)");
    puts("====================================");

    do{
    printf("1. Add Item\n");
    printf("2. Exit\n");
    printf(">>"); 
    
    scanf("%d", &input);
    if (input == 1){
        printf("Input item name: ");
        scanf("%s", &name); getchar();
        printf("Input item price: ");
        scanf("%d", &price);

        

        }
    }



    } while(input<1 && input>2);
}