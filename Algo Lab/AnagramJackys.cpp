#include <stdio.h>
#include <string.h>
#include <ctype.h>

//int main(){
//	
//	int input;
//	char word1[100];
//	char word2[100];
//	
//	int ascii1;
//	int ascii2;
//	int counter = 0;
//	
//	scanf("%d", &input);
//	for (int i = 0; i < input; i++){
//		int counter1[100] = {};
//		int counter2[100] = {};
//		scanf("%s %s", word1, word2);
//		strlwr(word1);
//		strlwr(word2);
//		if (strlen(word1) != strlen(word2)){
//			printf("No, It's not an anagram\n");
//		} else if (strlen(word1) == strlen(word2)){
//			for (int j = 0; j < strlen(word1); j++){
//				ascii1 = word1[j] - 97;
//				ascii2 = word2[j] - 97;
//				counter1[ascii1]++;
//				counter2[ascii2]++;
//			}
//			for (int k = 0; k < 26; k++){
//				if (counter1[k] != counter2[k]){
//					counter++;
//				}
//			}
//			if (counter == 0){
//				printf("Yes, it's an anagram\n");
//			} else {
//				printf("No, It's not an anagram\n");
//			}
//		}
//		counter = 0;
//	}
//	
//}

int main(){
	
	int input;
	char word1[50];
	char word2[50];
	
	int ascii1;
	int ascii2;
	
	scanf("%d", &input);
	for (int i = 0; i < input; i++){
		scanf("%s %s", word1, word2);
		int counter1[50] = {};
		int counter2[50] = {};
		int counter = 0;
		strlwr(word1);
		strlwr(word2);
		if (strlen(word1) != strlen(word2)){
			printf("Not Anagram\n");
		} else if (strlen(word1) == strlen(word2)){
			for (int j = 0; j < strlen(word1); j++){
				ascii1 = word1[j] - 97;
				ascii2 = word2[j] - 97;
				counter1[ascii1]++;
				counter2[ascii2]++;
			}
			for (int k = 0; k < 26; k++){
				if (counter1[k] != counter2[k]){
					counter++;
				}
			}
		}
		if (counter == 0){
			printf("Its Anagram\n");
		} else {
			printf("Its Not Anagram\n");
		}
	}
		
}





