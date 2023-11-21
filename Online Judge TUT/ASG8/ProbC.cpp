#include<stdio.h>
int main(){
	
	int cases;
	int num1, num2;
    
	scanf ("%d", &cases);
	for(int i = 0; i < cases; i++){
		scanf("%d %d", &num1, &num2);
		while(num1 != 1 && num2 != num1){
            if(num1 % 2 == 0){
			num1 = num1 / 2;
		}
		else if(num1 % 2 == 1){
			num1 = num1 * 3 + 1;
		}
	}
	if (num2 == num1){
			printf("Case #%d: YES\n", i+1);
		} else {
			printf("Case #%d: NO\n", i+1);		
		}
		
	}
}