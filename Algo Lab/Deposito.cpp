#include <stdio.h>

int main(){
	
	int input;
	int amount;
	int rate;
	int month;
	
	scanf("%d %d", &input, &amount);		
	for (int i = 0; i < input; i++){
		scanf("%d %d", &rate, &month);
	amount = amount + (amount * rate/100 * month/12);
	}
	printf("%d", amount);
}
