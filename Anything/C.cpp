#include <stdio.h>

int main(){
	
	int data;
	int index;
	int zero = 0;
	int counter = 0;
	int score[51] = {};
	
	scanf("%d%d", &data, &index);
	for (int i = 0; i < data; i++){
		scanf("%d", &score[i]);
	}
	for (int j = 0; j < data; j++){
		if (score[j] == 0){
			zero++;
		} else if (score[j] >= score[index-1]){
			counter++;
		}
	}
	if (zero == data){
		printf("0\n");
	} else {
		printf("%d\n", counter);
	}
	
}
