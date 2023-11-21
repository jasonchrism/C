#include <stdio.h>

int main( ) {

	int input, views, height;
	scanf("%d", &input);
	int heightArr[input];
	
	for(int i = 0; i < input; i++){
		scanf("%d", &height);
		heightArr[i] = height;
	}
	
	for(int i = 0; i < input; i++){
		height = heightArr[i];
		int space = height;	
		printf("Case #%d:\n", i+1);
		
		for(int j = 1; j <= height; j++){
			for(int k = 1; k <= height; k++){
				if(k < space){
					printf(" ");
				} else if ((k+j)%2 == 0){
					printf("*");
				} else {
					printf("#");
				}
			}
			printf("\n");
			space--;
		}
	}
	return 0;
		
}	
	

