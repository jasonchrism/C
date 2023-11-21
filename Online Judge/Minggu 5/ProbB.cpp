#include <stdio.h>
#include <string.h>

int main()
{

    char input[1000000];
    int vocal = 0;
    int consonant = 0;
    int arr[150];

    scanf("%[^\n]", input);
    for (int i = 0; i < strlen(input); i++)
    {
        // input[i] = tolower(input[i]);

        if (input[i] == 'a' || input[i] == 'i' || input[i] == 'u' || input[i] == 'e' || input[i] == 'o')
        {
            if (arr[input[i]] == 0)
            {
                vocal++;
                arr[input[i]]++;
            }
        }
        else if (input[i] != 32)
        {
            if (arr[input[i]] == 0)
            {
                consonant++;
                arr[input[i]]++;
            }
        }
    }
    printf("Vocal: %d\n", vocal);
    printf("Consonant: %d\n", consonant);
}