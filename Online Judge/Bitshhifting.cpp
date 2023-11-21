#include <stdio.h>

int main(){
	
	int a,b,c,d,e,f,g;
	
	scanf("%d", &a);
	scanf("%d%d", &b, &c);
	scanf("%d%d", &d, &e);
	scanf("%d%d", &f, &g);
	
	printf("%d\n", (b/c) << c);
	printf("%d\n", (d/e) << e);
	printf("%d\n", (f/g) << g);
	
	
}
