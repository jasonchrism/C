#include <stdio.h>
#include <string.h>

int main(){

    int cases;
    FILE *fp;
    fp = fopen("testdata.in", "r");
    fscanf(fp, "%d\n", &cases);
    char name[100];
    int change;
    char from;
    char to;
    for (int i = 0;i < cases; i++){
        int arr[150] = {};
        int count[150] = {};
        int counter[150] = {};
        fscanf(fp, "%s\n", name);
        fscanf(fp, "%d\n", &change);
        for (int j = 0; j < change; j++){
            fscanf(fp, "%c %c\n", &from, &to);
            if (arr[from] != 1){
                for (int k = 0; k < strlen(name); k++){
                    if (name[k] == from){
                        name[k] = to;
                    }
                }
                arr[from]++;
            }
        }
        for (int j = 0; j < strlen(name); j++){
            count[name[j]]++;
        }
        for (int j = 0; j < 128; j++){
            if (count[j] != 0){
                printf("%c %d\n", j, count[j]);
            }
        }
    }
    fclose(fp);
}