#include <stdio.h>
#include <string.h>

int palin(char* word, int len, int half, int temp, int count){
    if (half == count){
        return 1;
    }
    if (word[temp] == word[len-1]){
        return palin(word, len - 1, half, temp + 1, count + 1);
    } else if (word[temp] != word[len-1]){
        return 0;
    }
}

int main(){

    char word[100] = {};
    scanf("%s", word); getchar();
    int temp = 0;
    int count = 0;
    int len = strlen(word);
    int half = len / 2;
    int result = palin(word, len, half, temp, count);
    if (result == 1){
        printf("YA\n");
    } else {
        printf("BUKAN\n");
    }

}