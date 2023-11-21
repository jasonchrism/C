#include <stdio.h>

int main(){

    int input;
    long long int total = 0;
    long long int count = 0;
    
    scanf("%d", &input);
    int kasus;
    for (int i = 0; i < input; i++){
        scanf("%d", &kasus);
    
    int angka[kasus];
        for (int j = 0; j < kasus; j++){
            scanf("%d", &angka[j]);
            total = total + angka[j];
        }
        for (int k = 0; k < kasus; k++){    
            if (angka[k] >= total){
                count = count + 1;
            }
        } 
        
        printf("Case #%d: %lld\n", i + 1, total);
        printf("%lld\n", count);
        total = 0;
        count = 0;
    }

}