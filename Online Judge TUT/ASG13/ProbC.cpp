#include <stdio.h>
#include <stdlib.h>

int main()
{
    char kata[100];
    int halaman = 1, counter = 0;
    int essay = 1;

    FILE *file = fopen("testdata.in", "r");

    int jumlahkata;
    fscanf(file, "%d", &jumlahkata);

    while (fscanf(file, "%s", kata) == 1)
    {
        if (kata[0] == '#')
        {
            if (counter < jumlahkata)
            {
                essay = 0;
                printf("page %d: %d word(s)\n", halaman, counter);
            }
            counter = 0;
            halaman++;
        }
        else
        {
            counter++;
        }
    }

    if (essay == 1)
    {
        printf("The essay is correct\n");
    }
    fclose(file);
}