#include <stdio.h>
#include <stdio.h>

long long int MAXX = __LONG_LONG_MAX__;

void print(int pos, int k, int arr[], long long mid, int fin){
	long long count = 0;
	int X = -1;
	for (int i = pos; i >= 0; i--){
		if (count + arr[i] > mid || i == k - 2){
			print(i, k - 1, arr, mid, fin);
			X = i;
			break;
		}
		count += arr[i];
	}
	
	if (X >= 0){
		printf("; ");
	}

	for (int i = X + 1; i <= pos; i++){
		if (i == fin-1){
            printf("%d", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
	}
}

int check(int arr[], int diff, long long mid, int n){
	int temp = n;
    int i = 0;
    int X = 1;
	long long sum = 0;
	while (i < n){
		if (arr[i] > mid) return 0;
		if (sum + arr[i] > mid){
			X++; 
			sum = 0;
		}
		if (sum <= mid){
			sum = sum + arr[i];
			i++;
		}
	}
	
	if (X <= diff){
        return 1;
    }
	return 0;
}

long long binarySearch(int arr[], int diff, int n){
	long long low = 1, high = MAXX, ans = MAXX, mid;
	while (low < high){
		mid = low + (high-low)/2;
		int flag = check(arr, diff, mid, n);
		if (flag){
			ans = (ans < mid) ? ans : mid;
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return ans;
}

int main(){

	int cases;
	scanf("%d", &cases);
	
	while (cases--){
		int length;
        int city;
		scanf("%d %d", &length, &city);
		int arr[length + 1];
		for (int i = 0; i < length; i++){
            scanf("%d", &arr[i]);
        }
		long long limit = binarySearch(arr, city, length);
		print(length - 1, city, arr, limit, length);
		puts("");
	}
	
}