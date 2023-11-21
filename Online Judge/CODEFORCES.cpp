#include <stdio.h>

int main(){
	
	int a,b,c,j;
	scanf("%d%d%d", &a, &b, &c);
	j = 0;
	for(int i=a;j<b;i=i+c){
		printf("%d", i);
		i++;
	}

}
