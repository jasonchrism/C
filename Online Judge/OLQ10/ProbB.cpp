#include <stdio.h>
#include <math.h>

int main(){
    long long int num;
    long long int result;
    scanf("%lld", &num);
    result = pow(2,num) - 1;
    printf("%lld\n", result);

}