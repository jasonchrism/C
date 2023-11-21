#include <stdio.h>

struct matkul{
	char code[10];
	char name[100];
	int credits;
}matakuliah[1000];

int main (){
	int cases;
	scanf ("%d", &cases); getchar();
	for (int i = 0; i < cases; i++){
		scanf ("%s", matakuliah[i].code); getchar();
		scanf ("%[^\n]", matakuliah[i].name); getchar();
		scanf ("%d", &matakuliah[i].credits); getchar();
	}
	int ask, query;
	scanf ("%d", &ask);
	for (int i = 1; i <= ask; i++){
		scanf ("%d", &query);
		printf ("Query #%d:\n", i);
		printf ("Code: %s\n", matakuliah[query-1].code);
		printf ("Name: %s\n", matakuliah[query-1].name);
		printf ("Credits: %d\n", matakuliah[query-1].credits);
	}
}