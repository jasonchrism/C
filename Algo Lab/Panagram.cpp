#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	
	char word[150];
	int ascii;
	int counter = 0;
	
	int result[150] = {};
	
	printf("Input your word : ");
	scanf("%s", word);
	
	if (strlen(word) >= 26){
	for (int i = 0; i < strlen(word); i++){
		word[i] = tolower(word[i]);
		ascii = word[i] - 97;
		result[ascii]++;
	}
	
	for (int j = 0; j < 26; j++){
		if (result[j] < 0){
			counter++;
		}
		if (counter == 0){
			printf("Its Panagram");
		}
	}
}
	
	

	
}
