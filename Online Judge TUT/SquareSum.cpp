#include <stdio.h>

int main(){
	
	int a,b,c,d;
	float result;
	
	for(int i = 0; i < 3; i++){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		result = (a/1.0)*2.0+(b/2.0)*4.0+(c/3.0)*6.0+(d/4.0)*4.0;
		printf("%.2f\n", result);
	}	
}
