#include <stdio.h>

int main(){

    int T, N;

    scanf("%d", &T);
    for (int i  = 1; i <= T; i++){
        scanf("%d", &N);
        int max = 0;
        int temp = 0;
        int status = 0;
        int arr[200001];

        for (int j = 0; j < 200001; j++) arr[j] = 0;

        for (int j = 1; j <= N; j++){
            int index;
            scanf("%d", &index);
            temp = arr[index];
            temp++;
            
            if (temp > max){
                max = temp;
            }
            arr[index] = temp;
        }
        printf("Case #%d: %d\n", i, max);
        for (int k = 0; k < 200001; k++){
            if (arr[k] == max){
                printf("%s%d", status == 0 ? "" : " ", k);
                status++;
            }
        }
        printf("\n");
    }


}