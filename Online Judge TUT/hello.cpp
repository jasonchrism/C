#include <stdio.h>
#include <math.h>
int main()
{
        float a,b,c,d,x1,x2;
        printf(" Input coef. a : "); scanf("%f",&a);
        printf(" Input coef. b : "); scanf("%f",&b);
        printf(" Input coef. c : "); scanf("%f",&c);
        d = b*b - 4 * a * c;
        if (d >= 0){
	x1 = (-b + sqrt(d)) / (2 * a);
   		x2 = (-b - sqrt(d)) / (2 * a);
   		printf("x1=%f\n  x2=%f\n",x1,x2);
        }
        else printf(" Imaginer root equation");
        return 0;
}