#include <stdio.h>

int main(){
	
	int cases;
	int data, minutes;
	int count = 0;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++){
		int value[10000] = {};
		scanf("%d%d", &data, &minutes);
		for (int j = 0; j < data; j++){
			scanf("%d", &value[j]);
		}
		for (int k = 0; k < data - 1; k++){
			for (int j = 0; j < data - 1 - k; j++){
				if (value[j] > value[j+1]){
					int temp = value[j];
					value[j] = value[j+1];
					value[j+1] = temp;
					count++;
				}
			}
		}
		printf("Case #%d: %d\n", i + 1, count * minutes);
		count = 0;
	}
	
}
