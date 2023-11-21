#include <stdio.h>

int main(){

    int input;
    long long int total = 0;

    scanf("%d", &input);
    int kasus[input];
    for(int i = 0; i < input; i++){
        scanf("%d", &kasus[i]);
        long long int data[kasus[i]];
        for (int j = 0; j < kasus[i]; j++){
            scanf("%ld", &data[j]);
            total = total + data[j];
        }
        printf("Case #%d: %ld\n", i+1, total);
        total = 0;
    }

}