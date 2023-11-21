#include<stdio.h>

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    long long tmp;
    long long pivot = arr[(left + right) / 2];
 
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
 
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
int lower_bound(int  arr[], int N, int X)
{
    int mid;
 
    // Initialise starting index and
    // ending index
    int low = 0;
    int high = N;
 
    // Till low is less than high
    while (low < high) {
        mid = low + (high - low) / 2;
 
        // If X is less than or equal
        // to arr[mid], then find in
        // left subarray
        if (X <= arr[mid]) {
            high = mid;
        }
 
        // If X is greater arr[mid]
        // then find in right subarray
        else {
            low = mid + 1;
        }
    }
   
    // if X is greater than arr[n-1]
    if(low < N && arr[low] < X) {
       low++;
    }
       
    // Return the lower_bound index
    return low;
}

int main()
{
    int n, m, x;
    scanf("%d", &n);

    int arr[100050];
    for (int i = 0; i < n;i++)
    {
       scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    scanf("%d", &m);
    for (int i = 0; i < m;i++)
    {
        scanf("%d", &x);
        if(x<arr[0] || x>arr[n-1])
        {
            printf("-1\n");
            continue;
        }
        int found = lower_bound(arr, n - 1, x);
        if(found == -1)
            printf("-1\n");
        else
        {
            if(arr[found] != x)
                printf("-1\n");
            else
                printf("%d\n", found + 1);
        }
    }
}