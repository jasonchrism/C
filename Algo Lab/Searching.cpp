#include <stdio.h>

// void rec(int j, int *arr, int needToFind){
//     if (arr[j] == needToFind){
//         printf("Found %d in index %d\n", needToFind, j);
//         return;
//     }
//     rec(j+1, arr, needToFind);
// }

void doLinearSearch(){
    int arr[] = {10,20,30,40,50,60,70};
    int arrLength = sizeof(arr) / sizeof(arr[0]);

    int needToFind = 40;    //angka yg mau dicari
    int counter = 0;
    bool isFound = false;
    // int j = 0;
    // rec(j, arr, needToFind);
    for (int i = 0; i < arrLength; i++){
        if (arr[i] == needToFind){
            printf("Found %d in index %d\n", needToFind, i);
            break;
            isFound = true;
        }
            counter++;
    }

    if (isFound == false){
        printf("Data not found!\n");
    }
        // if (counter == arrLength){
        //     printf("Data not found!\n");
        // }
}

void binarySearch(){
    int arr[] = {10,20,30,40,50,60,70};
    int arrLength = sizeof(arr) / sizeof(arr[0]);

    int needToFind = 30;
    int mid = arrLength / 2;

    if (needToFind < arr[mid]){
        for (int i = 0; i < mid; i++){
            if (needToFind == arr[i]){
                printf("%d Found in index %d", needToFind, i);
                break;
            }
        }
    } else if (needToFind > arr[mid]){
        for (int i = mid + 1; i < arrLength; i++){
            if (needToFind == arr[i]){
                printf("%d Found in index %d", needToFind, i);
                break;
            }
        }
    } else if (needToFind == arr[mid]){
        printf("%d Found in index %d", needToFind, mid);
    }
}

void doBinarySearch(){
    int arr[] = {10,20,30,40,50,60,70};
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    int needToFind = 50;
    int leftIdx = 0;
    int rightIdx = arrLength - 1;

    while (leftIdx <= rightIdx){
        // int midIdx = (leftIdx + rightIdx) / 2;
        int midIdx = leftIdx + ((rightIdx - leftIdx) * (needToFind - arr[leftIdx]) / (arr[rightIdx] - arr[leftIdx]));
        if (arr[midIdx] == needToFind){
            printf("Found %d in index %d\n", needToFind, midIdx);
            break;
        } else if (arr[midIdx] < needToFind){
            leftIdx = midIdx + 1;
        } else if (arr[midIdx] > needToFind){
            rightIdx = midIdx - 1;
        }
    }
}


int main(){

    // doLinearSearch();
    // binarySearch();
    doBinarySearch();

}