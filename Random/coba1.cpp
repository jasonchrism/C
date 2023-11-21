#include <stdio.h>

int main(){

    // int input;
    // int abc = 65;

    // scanf("%d", &input);
    // for (int i = 0; i < input; i++){
    //     for (int j = 0; j <= i; j++)
    //     {
    //         printf("%c ", abc + j);
    //     }
    //     printf("\n");
    // }

    int diamond;
    int abc = 65;

    scanf("%d", &diamond);
    for (int i = 0; i < diamond; i++){
        for (int k = i; k <= diamond-1;k++){
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for (int i = 0; i <= diamond; i++){
        for (int k = 0; k < i; k++){
            printf(" ");
        }
        for (int j = i; j <= diamond; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    


    // float data, total, avg;
    // int a;
    // scanf("%d", &a);
    // for (int i = 0; i < a; i++)
    // {
    //     printf("Data ke-%d : ", i+1);
    //     scanf("%f", &data);
    //     total = total + data;
    // }
    // avg = total/a;
    // printf("The average is %.2f", avg);
    
    return 0;
}