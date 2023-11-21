#include <stdio.h>

int main(){
	
	int a = 0;
	int input;
	int result[100];
	int data[100][100];
	scanf("%d", &input);
	for (int i = 0; i < input; i++){
		for (int j = 0; j < input; j++){
			scanf("%d", &data[i][j]);
		}
	}
		
	for ( int i = 0; i < input; i++){
		for ( int j = 0 ; j < input; j++){
			if (data[i][j] + data[j][i] == 0){
				
			}
		}
	}
	
}
	
