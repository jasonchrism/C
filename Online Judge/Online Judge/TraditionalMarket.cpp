#include <stdio.h>

int main(){
	
	long int d,s,t;
	
	scanf("%d%d%d", &d,&s,&t);
	
	if(d > s && d > t){
		printf("Daging\n");
		if(s > t){
			printf("Sayur\n");
			printf("Telur\n");
		} else {
			printf("Telur\n");
			printf("Sayur\n");
		}
	} else if(s > d && s > t){
		printf("Sayur\n");
		if(d > t){
			printf("Daging\n");
			printf("Telur\n");
		} else {
			printf("Telur\n");
			printf("Daging\n");
		}
	} else if(t > d && t > s){
		printf("Telur\n");
		if(d > s){
			printf("Daging\n");
			printf("Sayur\n");
		} else {
			printf("Sayur\n");
			printf("Daging\n");
		}
	}

	
	
	
}
