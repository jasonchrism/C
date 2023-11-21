#include <stdio.h>

int main(){
	
	int input;
	
	printf("Operators\n");
	printf("==========\n");
	printf("Input your Favorite Number : ");
	scanf("%d", &input);
	
	float res1 = 2*input+3;
	printf("Result 1 = %.0lf\n", res1);
	
	double res2 = res1/3-4;
	printf("Result 2 = %.2lf\n", res2);
	
	double res3 = res2*res2;
	printf("Result 3 = %.2lf\n", res3);
	
	int *y = &input;
	printf("Y = %d\n", *y); 
	
	if(*y >= 10){
		printf("Y is bigger or equals 10\n");
	} else {
		printf("Y is smaller than 10\n");
	}
	
	printf((*y % 2 == 0) ? "Y is even\n" : "Y is odd\n");
	
	switch(*y){
		case 1:
			printf("Y is 1");
			break;
		
		case 2:
			printf("Y is 2");
			break;
			
		default:
			printf("Y is more than 2");
	}
	
	return 0;
}
