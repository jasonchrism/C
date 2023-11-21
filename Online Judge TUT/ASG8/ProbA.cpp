#include <stdio.h>

int main(){

    int n;
    int t1 = 0, t2 = 1;
    int nextTerm = t1 + t2;
    int result = 0;
    scanf("%d", &n);
    for (int i = 3; i <= n; ++i) {
        printf("%d", nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
        result = nextTerm + result;
    }
    printf("%d", result);

}