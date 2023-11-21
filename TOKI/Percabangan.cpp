#include <stdio.h>

void manhattan(){
    int x1,y1,x2,y2;
    int resultx = 0;
    int resulty = 0;
    int res;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if ((x1-x2) < 0){
        resultx = (x1-x2) * -1;
    } else {
        resultx = x1-x2;
    }    

    if ((y1-y2) < 0){
        resulty = (y1-y2) * -1;
    } else {
        resulty = y1-y2;
    }

    res = resultx + resulty;
    printf("%d", res);
}

void floorceil(){
    double num;
    scanf("%lf", &num);
    if (num < 0){
        printf("%.0lf %.0lf", num, num + 1);
    } else {
        printf("%.0lf %.0lf", num, num + 1);
    }
}

int main(){

    floorceil();

}