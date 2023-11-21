#include <stdio.h>
#include <string.h>

//int main(){
//	
//	char input[100];
//	scanf("%s", input);
//	
//	int len = strlen(input);
//	int half = len / 2;
//	int a = 0;
//	
//	for (int i = 0; i < half; i++){
//		if (input[i] == input[len-1]){
//			a++;
//		}
//		len--;
//	}
//	if (a == half){
//		printf("Palindrome\n");
//
//	} else {
//		printf("Not Palindrome\n");
//	}
//	
//}

//int main(){
//	
//	int input;
//	char word[50];
//	
//	scanf("%d", &input);
//	for (int i = 0;i < input; i++){
//		scanf("%s", word);
//		int len = strlen(word);
//		int half = len / 2;
//		for (int j = 0; j < half; j++){
//			int l = 0, r = len-1;
//			while (l < r){
//				word[r--] = word[l++];
//			}
//		}
//		printf("%s\n", word);
//	}
//	
//}

int main(){
	
	int input;
	char word[50];
	
	scanf("%d", &input);
	for (int i = 0; i < input; i++){
	int a = 0;
		scanf("%s", word);
		int len = strlen(word);
		int half = len / 2;
		for (int j = 0; j < half; j++){
			if (word[j] == word[len-1]){
				a++;
			}
			len--;
		}
		if (a == half){
			printf("Palindrome\n");
		} else {
			printf("Not Palindrome\n");
		}
		a = 0;
	}
	
}




















