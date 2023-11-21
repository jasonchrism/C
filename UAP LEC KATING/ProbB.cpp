#include <stdio.h>

int main(){
	
	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++){
		int lines;
		scanf("%d", &lines);
		int x[100] = {};
		int y[100] = {};
		int tempx[100] = {};
		int tempy[100] = {};
		for (int j = 0; j < 4*lines-1; j++){
			scanf("%d %d", &x[j], &y[j]);
			tempx[x[j]]++;
			tempy[y[j]]++;
		}
		for (int j = 0; j < 4*lines-1; j++){
			if (tempx[x[j]] % 2 == 1){
				printf("Case #%d: %d ", i + 1, x[j]);
			} 
		}
		for (int j = 0; j < 4*lines-1; j++){
			if (tempy[y[j]] % 2 == 1){
				printf("%d", y[j]);
			}
		}
	}
	
}
