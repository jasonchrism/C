#include <stdio.h>

int main(){
	
	int input;
	int data1[100][100];
	int data2[100][100];
	int result[100][100];
	printf("Input Ordo : ");
	scanf("%d", &input);
	
	for (int i = 0; i < input; i++){
		for (int j = 0; j < input; j++){
			scanf("%d", &data1[i][j]);
		}
	}
	
	for (int i = 0; i < input; i++){
		for (int j = 0; j < input; j++){
			scanf("%d", &data2[i][j]);
		}
	}
	
	for (int i = 0; i < input; i++){
		for (int j = 0; j < input; j++){
			result[i][j] = 0;
			for (int k = 0; k < input; k++){
				result[i][j] = result[i][j] + data1[i][k] * data2[k][j];
			}
		}
	}
	
	printf("Result : \n");
	
	for (int i = 0; i < input; i++){
		for (int j = 0; j < input; j++){
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}
