#include <stdio.h>
#include <string.h>

int main (){

    int input;  
    int a = 0;
    char counter[500];
    
    scanf("%d", &input);
    for (int i = 0; i < input; i++){
        scanf("%s", counter);
        int len = strlen(counter);
        int half = len / 2;

        for (int j = 0; j < half; j++){
            if (counter[j] == counter[len-1]){
                a++;
            }
            len--;
        }
        printf("Case #%d: ", i + 1);
        if (a == half){
            printf("Yay, it's a palindrome\n");
        } else {
            printf("Nah, it's not a palindrome\n");
        }
        a = 0;
    }



}