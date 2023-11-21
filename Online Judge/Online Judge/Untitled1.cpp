#include <stdio.h>

int main(){
	
	int day, friends, a, b;
	int view[150];
	scanf("%d", &day);
	
	for(int i = 0; i < day; i++){
		scanf("%d", &view[i]);
	}
	scanf("%d", &friends);
	for (int j = 0;j < friends; j++){
		scanf("%d%d", &a, &b);
		printf("Case #%d : ", j+1);
		int sum = 0;
		for(int k = a-1;k <= b-1;k++){
			sum = sum + view[k];
		}
		printf("%d\n", sum);
	}
}
