#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int row1;
	int column1;
	int row2;
	int column2;
	int matrix1[100][100];
	int matrix2[100][100];
	int result[100][100];

	printf("Input Row and Column First Matrix : ");
	scanf("%d%d", &row1, &column1);
	printf("Input Row and Column Second Matrix : ");
	scanf("%d%d", &row2, &column2);
	
	if (column1 != row2){
		printf("Cannot Do The multiplication!\n");
		printf("Press enter to exit.."); getchar(); getchar();
		system("cls");
	}
	
	for (int i = 0; i < row1; i++){
		for (int j = 0; j < column1; j++){
			scanf("%d", &matrix1[i][j]);
		}
	}

	for (int i = 0; i < row2; i++){
		for (int j = 0; j < column2; j++){
			scanf("%d", &matrix2[i][j]);
		}
	}
	
	for (int i = 0; i < row1; i++){
		for (int j = 0; j < column2; j++){
			result[i][j] = 0;
			for (int k = 0; k < row2; k++){
				result[i][j] = result[i][j] + matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	
	for (int i = 0; i < row1; i++){
		for (int j = 0; j < column2; j++){
			printf("%d  ", result[i][j]);
		}
		printf("\n");
	}
	
}
