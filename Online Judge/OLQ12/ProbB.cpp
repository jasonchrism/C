#include <stdio.h>
#include <math.h>

int partition(int num[], int left, int right){
    int i = left-1;
    int j = left;
    int pivot = num[right];

    while (j < right){
        if (num[j] < pivot){
            i++;
            int temp = num[j];
            num[j] = num[i];
            num[i] = temp;
        }
        j++;
    }
    num[right] = num[i + 1];
    num[i + 1] = pivot;
    return (i+1);
}

void quickSort(int num[], int left, int right){
    if (left < right){
        int pos = partition(num, left, right);
        quickSort(num, left, pos - 1);
        quickSort(num, pos + 1, right);
    }
}

int main(){

    int cases;
    scanf("%d", &cases);
    int compare;
    for (int i = 0; i < cases; i++){
        scanf("%d", &compare);
        int num[1000] = {};
        for (int j = 0; j < compare; j++){
            scanf("%d", &num[j]);
        }
        quickSort(num, 0, compare-1);
        int min = 1000000;
        for (int j = compare - 1; j >= 0; j--){
            for (int k = j-1; k >= 0; k--){
                int gap = num[j] - num[k];
                if (gap < min){
                    min = num[j] - num[k];
                }
            }
        }
        printf("Case #%d: %d\n", i + 1, min);
        min = 1000000;
    }

}