#include <stdio.h>
#include <string.h>

int main(){

    // char data[1000];
    // scanf("%s", data);

    // if (strlen(data) == 1){
    //     printf("%c", data[0]);
    //     return 0;
    // }
    // for (int i = 0; i < strlen(data); i++){
    //     if (data[i] != '0'){
    //         printf("%c", data[i]);
    //         for (int j = 0; j < strlen(data)-i-1; j++){
    //             printf("0");
    //             printf(" ");
    //         }
    //     }
    // }

    // int a[100][100];
    // int n;
    // scanf("%d", &n);

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         scanf("%d", &a[i][j]);
    //     }
    // }

    // for (int i = 1; i < n-1; i++){
    //     for (int j = 1; j < n-1; j++){
    //         printf("%d", a[i][j]);
    //         if (j < n-2){
    //             printf(" ");
    //         } else {
    //             printf("\n");
    //         }
    //     }
    // }

//Palindrome

    int input;

    scanf("%d", &input);
    for (int i = 0; i < input; i++){
        char string[100]; gets(string);
        int length = strlen(string);
        int l = 0; int r = length-1;
        while (l < r){
            string[r--] = string[l++];
        }
        printf("%s\n", string);
    }

    

}



