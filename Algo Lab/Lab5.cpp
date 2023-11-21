#include <stdio.h>
#include <string.h>

char userIds[5][25] = {"christ0208", "jordywa", "haku", "elior", "cleo"};
char names[5][255] = {"Christopher", "Jordy", "Haku", "Eleanor", "Cleo Deus"};
char emails[5][255] = {"chris@gmail.com", "jordy@gmail.com", "haku@gmail.com", "el@gmail.com", "cleo@gmail.com"};

int friendList[5];
int friendCount = 0;

int main(){

    int input;

    puts("Friendster CLI");
    puts("==============");

    do{
        puts("1. Add New Friend");
        puts("2. Unfriend");
        puts("3. Exit");
        printf(">> ");
        scanf("%d", &input); getchar();

        if (input == 1){
            char key[255];
            printf("Input your keyword : ");
            scanf("%[^\n]", key); getchar();

        int result = 0;
        int resultIndex[5];


        // resultindex = {0,1,3,4}

            for (int i = 0; i < 5; i++){
                if (strcmpi(userIds[i], key) == 0 || strstr(strlwr(names[i]), strlwr(key)) != NULL){
                    resultIndex[result] = i;
                    result++;
                    printf("%d. %s |  % s |  % s | \n", result, userIds[i], names[i], emails[i]);
                }
            }
            
            if (result == 1){
                char yn[4];
                printf("Do you want to add this friend? [yes|no] : ");
                scanf("%s", yn); getchar();

                if (strcmp("yes", yn) == 0){

                friendList[friendCount] = resultIndex[0];
                friendCount++;
                }
            }

            // friendList = {3}

            if (result > 1){
                int choice;
                printf("Input the number you want to add : ");
                scanf("%d", &choice); getchar();

                if (choice != 0){
                    friendList[friendCount] = resultIndex[choice-1];
                    friendCount++;
                }
            }
        }
        if (input == 2){
                int choice = 0;
                for (int i = 0; i < friendCount; i++){
                    int index = friendList[i];
                    printf("%d. | %s | %s | %s\n", i+1, userIds[index], names[index], emails[index]);
                }
                printf("Pick a number you want to unfriend [0 to exit] : ");
                scanf("%d", &choice); getchar();
                if (choice != 0){
                    for (int i = choice-1; i < friendCount-1; i++){
                        friendList[i] = friendList[i+1];
                    }
                friendCount--;
                }
            }
    } while (input != 3);

    return 0;
}