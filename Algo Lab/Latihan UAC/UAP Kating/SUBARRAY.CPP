#include <stdio.h>

void subArray(int num[], int start, int end, int size){
	if (end == size) return;
	else if (start > end) subArray(num, 0, end + 1, size);
	else {
		for (int i = start; i <= end; i++) printf("%d%s", num[i], i == end ? "\n" : " ");
		subArray(num, start + 1, end, size);
	}
	return;
}

int main(){
	
	int input;
	scanf("%d", &input);
	int num[input];
	for (int i = 0; i < input; i++){
		scanf("%d", &num[i]);
	}
	subArray(num, 0, 0, input);
	return 0;
}

//// C code to print all possible subarrays for given array
//// using recursion
//#include <stdio.h>
//// Recursive function to print all possible subarrays for
//// given array
//void printSubArrays(int arr[], int start, int end, int size){
//	if (end == size) return;
//	else if (start > end)
//        printSubArrays(arr, 0, end + 1, size);
//   
//    // Print the subarray and increment the starting point
//    else {
//        printf("[");
//        for (int i = start; i < end; i++)
//            printf("%d, ", arr[i]);
//       
//        // cout << arr[i] << ", ";
//        printf("%d]\n", arr[end]);
//       
//        // cout << arr[end] << "]" << endl;
//        printSubArrays(arr, start + 1, end, size);
//    }
//    return;
//}
// 
//int main()
//{
//    int arr[] = { 1, 2, 3 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    printSubArrays(arr, 0, 0, n);
//    return 0;
//}

// This code is contributed by Sania Kumari Gupta

//#include <stdio.h>
//
//int main(){
//	
//	int input;
//	scanf("%d", &input);
//	int num[100];
//	for (int i = 0; i < input; i++){
//		scanf("%d", &num[i]);
//	}
//	for (int i = 0; i < input; i++){
//		for (int j = i; j < input; j++){
//			for (int k = i; k <= j; k++){
//				printf("%d", num[k]);
//			}
//			printf("\n");
//		}
//	}
//
//}
