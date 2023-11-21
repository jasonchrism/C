#include <stdio.h>

struct Student{
	char ID[1000];
	char name[1000];
	int age;
}students[1000];

int main(){
	
	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++){
		scanf("%s", students[i].ID); getchar();
		scanf("%[^\n]", students[i].name); getchar();
		scanf("%d", &students[i].age); getchar();
	}
	int query;
	int ask;
	scanf("%d", &query);
	for (int i = 0; i < query; i++){
		scanf("%d", &ask);
		printf("Query #%d:\n", i + 1);
		printf("ID: %s\n", students[ask].ID);
		printf("Name: %s\n", students[ask].name);
		printf("Age: %d\n", students[ask].age);
	}
}
