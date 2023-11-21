#include <stdio.h>
#include <math.h>

int main(){
	
	int N;
	scanf("%d", &N);
	
	int star = pow(2,N) - 1;
	int space;
	for (int i = 0; i < N; i++){
		space = pow(2,i) - 1;
		for (int j = 0; j < star; j++){
			for (int k = 0; k < space; k++){
				printf(" ");
			}
			printf("*");
		}
		printf("\n");
	star = star / 2;
	}
}
