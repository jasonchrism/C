#include <stdio.h>

int main(){
	
	int input;
	int result = 0;
	scanf("%d", &input);
	for (int i = 0; i < input; i++){
		int counter = 0;
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1){
			counter++;
		}
		if (b == 1){
			counter++;
		}
		if (c == 1){
			counter++;
		}
		if (counter >= 2){
			result = result + 1;
		}
	}
		printf("%d\n", result);
	
}
