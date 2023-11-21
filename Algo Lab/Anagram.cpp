#include <stdio.h>
#include <string.h>

int main(){
	
	char fWord[150];
	char sWord[150];
	
	int counter1[150] = {};
	int counter2[150] = {};
	int counter = 0;
	
	int fiWord;
	int seWord;
	
	printf("First Word : ");
	scanf("%s", fWord);
	
	printf("Second Word : ");
	scanf("%s", sWord);
	
	if (strlen(fWord) != strlen(sWord)){
		printf("Not Anagram\n");
	} else if (strlen(fWord) == strlen(sWord)){
		for (int i = 0; i < strlen(fWord); i++){
			fiWord = fWord[i] - 97;
			seWord = sWord[i] - 97;
			counter1[fiWord]++;
			counter2[seWord]++;
		}
		for (int j = 0; j < 26; j++){
			if (counter1[j] != counter2[j]){
				counter++;
			}
		}
		if (counter == 0){
			printf("Its Anagram\n");
		} else {
			printf("Not Anagram\n");
		}
	}
	
}
