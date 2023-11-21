#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main()
{
    int assignClass, assignLab;
    int midClass, midLab, finalScore;
    int finalClass, finalLab;
    float scoreClass, scoreLab;
    char answer;

    system("cls");
    printf(" Continue [Y/T] ? ");
    scanf("%c", &answer);
    while (toupper(answer) == 'Y')
    {
        printf(" Assign class(0 - 100) : ");
        scanf("%d", &assignClass);
        printf(" Assign lab(0 - 100): ");
        scanf("%d", &assignLab);
        printf(" mid class(0 - 100): ");
        scanf("%d", &midClass);
        printf(" mid lab(0 - 100): ");
        scanf("%d", &midLab);
        printf(" fin class(0 - 100): ");
        scanf("%d", &finalClass);
        printf(" fin class(0 - 100): ");
        scanf("%d", &finalLab);
        scoreClass = 0.2 * assignClass + 0.3 * midClass + 0.5 * finalClass;
        scoreLab = 0.3 * assignLab + 0.3 * midLab + 0.4 * finalLab;
        finalScore = ceil(0.8 * scoreClass + 0.2 * scoreLab);
        if (finalScore >= 85)
        {
            printf("finalScore = A");
        }
        else if (finalScore >= 75)
        {
            printf("finalScore = B");
        }
        else if (finalScore >= 65)
        {
            printf("finalScore = C");
        }
        else if (finalScore >= 50)
        {
            printf("finalScore = D");
        }
        else
        {
            printf("finalScore = E");
        }
        printf("\n");
    }
    printf("Continue[Y/T] ? ");
    scanf("%c", &answer);
}
