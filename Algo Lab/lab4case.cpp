#include <stdio.h>
#include <string.h>


int main() {
    int input, prices[20], counter = 0;
    char names[20][50];
    do {
        for (int i = 0; i < counter; i++) {
            printf("%s %d\n", names[i], prices[i]);
        }
        
        printf("1. Add Item\n");
        printf("2. Exit\n");
        printf(">> ");
        scanf("%d", &input);
        getchar();

        switch (input) {
        case 1:
            char name[50];
            printf("Input item name: ");
            scanf("%[^\n]", &name);
            strcpy(names[counter], name);

            int price;
            printf("Input item price: ");
            scanf("%d", &price);
            prices[counter] = price;

            counter++;
            break;
        
        case 2:
            printf("Thank you for using the app!\n");

        default:
            break;
        }
    } while (input != 2);
    
}