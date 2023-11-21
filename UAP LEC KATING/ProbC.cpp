#include <stdio.h>

int partition(int num[], int low, int high){
	int i = low - 1;
	int j = low;
	int pivot = num[high];
	while (j < high){
		if (num[j] <= pivot){
			i++;
			int temp = num[j];
			num[j] = num[i];
			num[i] = temp;
		}
		j++;
	}
	num[high] = num[i+1];
	num[i+1] = pivot;
	return (i+1);
}

void quickSort(int num[], int low, int high){
	if (low < high){
		int pos = partition(num, low, high);
		quickSort(num, low, pos - 1);
		quickSort(num, pos, high);
	}
}

int main(){
	
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++){
		int num[100] = {};
		int start = 1;
		int inputNum;
		double quartil = 0;
		int temp = 0;
		int index = 0;
		double result = 0;
		double multiply = 0;
		scanf("%d", &inputNum); 
		
		for (int j = 0; j < inputNum; j++){
			scanf("%d", &num[j]);
		}
		quickSort(num, 0, inputNum - 1);
		for (int j = 0; j < inputNum; j++){
			printf("%d ", num[j]);
		}
		printf("Case #%d:", i + 1);
		for (int j = 0; j < 3; j++){
			quartil = start * (inputNum + 1) / 4;
			temp = start * (inputNum + 1) / 4;
			multiply = quartil - temp;
			printf("%.2lf", multiply);
			index = quartil - multiply;	
			for (int k = 0; k < 2; k++){
				result = result + num[index] * multiply;
				index++;
			}
			printf(" %.2lf", result);
			start++;
			quartil = 0;
			temp = 0;
			index = 0;
		}
		printf("\n");
	}
	
}
