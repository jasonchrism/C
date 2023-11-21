#include <stdio.h>
#include <string.h>

int main(){

    int N, M;
    int index;

    scanf("%d%d", &N, &M);
    char counter[N];
    scanf("%s", counter);
        for (int j = 0; j < M; j++){
            scanf("%d", &index);
            if (counter[index] > 96){
                counter[index] -= 32;
            } else {
                counter[index] += 32;
            }
        }
        printf("%s\n", counter);

}