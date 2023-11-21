#include <stdio.h>
#include <stdlib.h>

struct course{
    int score;
    char subject[30];
};

int main(){

    struct course *ptr;
    int records;
    printf("Input the number of records : ");
    scanf("%d", &records);

    ptr = (struct course*)malloc(records * sizeof(struct course));
    for (int i = 0; i < records; i++){
        printf("Enter subject and score : ");
        scanf("%s %d", (ptr+i) -> subject, &(ptr+i) -> score);
    }

    printf("Course Record : \n");
    for (int i = 0; i < records; i++){
        printf("%s\t: %d\n", (ptr+i) -> subject, (ptr+i) -> score);
    }

}