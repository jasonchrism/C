#include <stdio.h>
#include <string.h>

struct tree{
    char name[100];
    char plant[100];
    char friends[100];
};

int main(){

    tree data[100];
    int ask;
    int list;
    FILE* filePointer;
    filePointer = fopen("testdata.in", "r");
    fscanf(filePointer, "%d", &list); fgetc(filePointer);
    for (int i = 0; i < list; i++){
        fscanf(filePointer, "%[^#]#%[^\n]\n", data[i].name, data[i].plant);
    }
    fscanf(filePointer, "%d", &ask); fgetc(filePointer);
    for (int i = 0; i < ask; i++){
        int check = 0;
        fscanf(filePointer, "%s\n", data[i].friends);
        for (int j = 0; j < list; j++){
            if (strcmp(data[i].friends, data[j].name) == 0){
                printf("Case #%d: %s\n", i + 1, data[j].plant);
                check = 1;
                break;
            }
        }
        if (check == 0){
            printf("Case #%d: N/A\n", i + 1);
        }
    }
}