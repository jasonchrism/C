#include <stdio.h>

void binary(long long int num)
{
    if (num > 1)
        binary(num / 2);
    printf("%llu", num % 2);
}

int main()
{
    int cases;
    long long int num;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++)
    {
        scanf("%llu", &num);
        printf("Case #%d: ", i + 1);
        binary(num);
        printf("\n");
    }
}