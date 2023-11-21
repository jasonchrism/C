#include <stdio.h>

int main()
{

    int input;
    int height, widht;
    int right, size;
    int end;

    do{

    printf("Shape Printer\n");
    printf("=============\n");
    printf("1. Rectaangle\n");
    printf("2. Right Triangle (90 degree Triangle)\n");
    printf("3. Equilateral Triangel\n");
    printf("4. Exit\n");
    printf(">> ");

    scanf("%d", &input);

    if (input == 1)
    {
        printf("Input Rectangle Widht [must be more than 0]:");
        scanf("%d", &widht);
        printf("Input rectangle Height [must be more than 0]: ");
        scanf("%d", &height);
        printf("Result: \n");
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < widht; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }

    else if (input == 2)
    {
        printf("Input Right Triangle Size [must be more than 0]: ");
        scanf("%d", &right);
        for (int i = 0; i < right; i++)
        {
            for (int k = i; k < right; k++)
            {
                printf(" ");
            }
            for (int j = 0; j <= i; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }

    else if (input == 3)
    {   
        do{
        printf("Input Equilateral Triangle Size [must be more than 0 and odd number]: ");
        scanf("%d", &size);
        }while(size%2 == 0); 
        
        for (int i = 0; i < size/2+1; i++){
            for (int j = i; j < size - size/2-1; j++){
                printf(" ");
            }
            for (int k = 0; k <= (2*i); k++){
                printf("*");
            }
            printf("\n");
            }
    }

    else if (input == 4){
        printf("Thank you for using this app!\n");
        end = 1;
    }

    else {
        printf("You must input valid menu number!\n");
    }
    } while (end != 1);
}