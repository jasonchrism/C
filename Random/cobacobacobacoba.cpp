#include <stdio.h>

int partition(int num[], int low, int high)
{
    
    int pivot = num[high];
    int i = low - 1;
    int j = low;
    while (j < high)
    {
        if (num[j] <= pivot)
        {
            i++;
            int temp = num[j];
            num[j] = num[i];
            num[i] = temp;
        }
        j++;
    }
    num[high] = num[i + 1];
    num[i + 1] = pivot;
    return (i + 1);
}

void quickSort(int num[], int low, int high)
{
    if (low < high)
    {
        int pos = partition(num, low, high);
        quickSort(num, low, pos - 1);
        quickSort(num, pos, high);
    }
}

int main()
{

    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++)
    {
        int num[100] = {};
        int inputNum;
        scanf("%d", &inputNum);

        for (int j = 0; j < inputNum; j++)
        {
            scanf("%d", &num[j]);
        }
        quickSort(num, 0, inputNum - 1);
        for (int j = 0; j < inputNum; j++)
        {
            printf("%d ", num[j]);
        }
    }
}