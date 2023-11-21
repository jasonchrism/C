#include <stdio.h>
#include <string.h>

int main(){
	
	int cases, nameCount, ask;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++){
		char name[1000][1000] = {};
		char temp[1000] = {};
		scanf("%d%d", &nameCount, &ask);
		for (int j = 0; j < nameCount; j++){
			scanf("%s", name[j]); getchar();
		}

		for (int j = 0; j < nameCount; j++){
			for (int k = j + 1; k < nameCount; k++){
				if (strcmp(name[j], name[k]) > 0){
					strcpy(temp, name[j]);
					strcpy(name[j], name[k]);
					strcpy(name[k], temp);
				}
			}
		}
		printf("Case #%d: %s\n", i + 1, name[ask-1]);
	}
	
}
