#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    long long int arr[5000] = {};
    long long int temp[5000] = {};
    int num;
    long long int value;

    scanf("%d", &N);
    temp[0] = 0;
    for (int i = 1; i <= N; i++){
        scanf("%lld", &value);
        temp[i] = value + temp[i - 1];
    }

    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        long long int ask;
        scanf("%lld", &ask);
        int max = -1;
        for (int j = 0; j < N; j++){
            for (int k = N; k >= j + 1; k--){
                if(temp[k]-temp[j] <= ask){
                    if(k - j > max){
                        max = k - j;
                        break;
                    }if(k - j < max){
                        break;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", i + 1, max);
    }
}
