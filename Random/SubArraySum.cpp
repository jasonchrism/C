#include <stdio.h>

void SubArraySum(int array[], int size, int target){
    for (int i = 1; i< size; i++) array[i] = array[i - 1] + array[i];
    for (int i = 0; i < size; i++){
        for (int j = 1 + 1; j < size; j++){
            if (array[j] - array[i] == target) {printf("Found between %d and %d\n", target, i + 1, j); return;
            }
        }
    }
    printf("%s", "Target not found\n");
}

int main(){

    int input;
    scanf("%d", &input);
    int num[100];
    for (int i = 0; i < input; i++){
        scanf("%d", &num[i]);
    }
    int target;
    scanf("%d", &target);
    SubArraySum(num, input, target);

}