#include <stdio.h>
#include <string.h>

int main(){
	
	int input;

	scanf("%d", &input);
	for (int i = 0; i < input; i++){
	char data[101] = {};
		scanf("%s", data);
		int len = strlen(data) - 2;
		if(strlen(data) <= 10){
			printf("%s\n", data);
		} else {
		printf("%c%d%c\n", data[0], len, data[len+1]);
		}
	}
}
