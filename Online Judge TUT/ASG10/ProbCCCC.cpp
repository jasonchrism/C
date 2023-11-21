#include <stdio.h>

int main(){

    int cust;
    int counter = 0;
    scanf("%d", &cust);
    long long int key;
    long long int arr[cust];
    for (int i = 0; i < cust; i++){
        scanf("%lld", &key);
        int check = 1;
        for (int j = 0; j < counter; j++){
            if (arr[j] == key){
                check = 0;
            }
        }
        
        if (check == 1){
            arr[counter] = key;
            counter++;
        }
    }
    printf("%d\n", counter);

}