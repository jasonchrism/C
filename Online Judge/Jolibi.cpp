#include <stdio.h>

int main(){
	
	int input, counter, score, jojo, lili, bibi;
	scanf("%d", &input);
	scanf("%d%d%d", &jojo, &lili, &bibi);
	score = 0;
	
	for(int i = 0; i < input; i++){
		scanf("%d", &counter);
		score += counter;
	}
	int result = (jojo+lili+bibi+score)/(input+3);
	
	if(jojo >= result){
		printf("Jojo lolos\n");
	} else {
		printf("Jojo tidak lolos\n");
	}
	
	if(lili >= result){
		printf("Lili lolos\n");
	} else {
		printf("Lili tidak lolos\n");
	}

	if(bibi >= result){
		printf("Bibi lolos\n");
	} else {
		printf("Bibi tidak lolos\n");
	}
	
}
