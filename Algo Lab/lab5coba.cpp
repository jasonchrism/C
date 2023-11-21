#include <stdio.h>
#include <string.h>

char userID[6][255] = {"jece", "aryo", "jul", "dustin", "yoga", "daniel11"};
char name[6][255] = {"Jason CM", "Aryo B", "Joel E", "Dustin B", "I Yoga", "Daniel C"};
char email[6][255] = {"jason@gmail.com", "aryo@gmail.com", "joel@gmail.com", "dustin@gmail.com", "yoga@gmail.com", "daniel@gmail.com"};

char friendList[6];
int friendCount = 0;

int main()
{

    puts("Friendster CLI");
    puts("===============");

    int input;
    int add;

    do
    {
        puts("1. Add New Friend");
        puts("2. Unfriend");
        puts("3. Exit");
        printf(">> ");
        scanf("%d", &input);
        getchar();

        if (input == 1)
        {
            char key[50];
            printf("Enter keyword to search a friend [must not be empty]: ");
            scanf("%[^\n]", key);
            getchar();

            char resultIndex[6];
            int resultCount = 0;

            for (int i = 0; i < 6; i++)
            {
                if (strcmpi(userID[i], key) == 0 || strstr(strlwr(name[i]), strlwr(key)) != NULL)
                {
                    resultIndex[resultCount] = i;
                    resultCount++;
                    printf("%d. %s | %s | %s | \n", resultCount, userID[i], name[i], email[i]);
                }
            }
            if (resultCount == 1)
            {
                char yn[10];
                printf("Do you want to add this user as your friend? [yes/no] : ");
                scanf("%[^\n]", yn);
                getchar();
                if (strcmp("yes", yn) == 0)
                {
                    friendList[friendCount] = resultIndex[0];
                    friendCount++;
                }
            }
            if (resultCount > 1)
            {
                printf("Pick number which friend you want to add [type '0' to cancel add friend] : ");
                scanf("%d", &add);
                getchar();

                if (add != 0)
                {
                    friendList[friendCount] = resultIndex[add - 1];
                    friendCount++;
                }
            }
        }
        if (input == 2)
        {
            for (int i = 0; i < friendCount; i++)
            {
                int index = friendList[i];
                printf("%d. %s | %s | %s |\n", i + 1, userID[index], name[index], email[index]);
            }
            int remove;
            printf("Enter the index number to remove friend [type '0' to cancel] : ");
            scanf("%d", &remove);
            if (remove != 0)
            {
                for (int i = remove - 1; i < friendCount - 1; i++)
                {
                    friendList[i] = friendList[i + 1];
                }
                friendCount--;
            }
        }
    } while (input != 3);
}