#include <stdio.h>
#include <string.h>

struct name{
    char nameFriends[100];
    int numFriends;
}friends[100];

int main(){

    int cases;
    int ask;
    scanf("%d %d", &cases, &ask); getchar();
    for (int i = 0; i < cases; i++){
        scanf("%s %d", friends[i].nameFriends, &friends[i].numFriends); getchar();
    }

    for (int i = 0; i < ask; i++){
    int check = 1;
    char askName[100] = {};
    scanf("%s", askName); getchar();
        for (int j = 0; j < cases; j++){
            if (strcmp(askName, friends[j].nameFriends) == 0){
                printf("%d\n", friends[j].numFriends);
                check = 0;
            }
        }
        if (check == 1){
            printf("NIHIL\n");
        }
    }

}