#include <stdio.h>
int main()
{
    //     float val1, val2;
    //     char op;
    //     while (1)
    //     {
    //         printf("\n Type val1 operator val2, (example : 3 * 4) \n");
    //         scanf("%f %c %f", &val1, &op, &val2);
    //         if (op == '+' /*  */)
    //             printf(" = % f", val1 + val2);
    //         else if (op == '-')
    //             printf(" = % f", val1 - val2);
    //         else if (op == '*')
    //             printf(" = % f", val1 * val2);
    //         else if (op == '/')
    //             printf(" = % f", val1 / val2);
    //         else
    //         {
    //             printf(" error: choose operator+, -, *and / \n");
    //             break;
    //         }
    //     }
    //     return 0;
    // }

//     float val1, val2;
//     char op;
//     while (1)
//     {
//         printf("\n Type val1 operator val2 \n");
//         scanf("%f %c %f", &val1, &op, &val2);
//         switch (op)
//         {
//         case ('+'):
//             printf(" = %f", val1 + val2);
//             break;
//         case ('-'):
//             printf(" = %f", val1 - val2);
//             break;
//         case ('*'):
//             printf(" = %f", val1 * val2);
//             break;
//         case ('/'):
//             printf(" = %f", val1 / val2);
//             break;
//         default:
//             printf(" unknown operator!");
//         }
//     }
//     return (0);
// }

int diamond;
scanf("%d", &diamond);
for (int i = 1; i <= diamond; i++){
        for (int k = 0; k < i; k++){
            printf(" ");
        }
        for (int j = i; j <= diamond; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}