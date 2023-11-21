#include<stdio.h>
int n;
long long int a[100010];
long long int allSum[100010]={};

int binarySearch(long long search)
{
	int high = n-1;
	int low = 0;
	int mid;
	while(low<high)
	{
		mid = (low+high)/2;
		if(search<=allSum[mid])
		{
			high = mid;
		}
		else
		{
			low = mid+1;
		}
	}
	if(allSum[low]!=search)
	{
		return low-1;
	}
	else return low;
	
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	long long int sum=0;
	for(int j=0;j<n;j++){
		sum = sum + a[j];
		allSum[j]=sum;	
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		long long int x;
		scanf("%lld",&x);
		
		int hasil = binarySearch(x);
		if (x < allSum[0]) hasil = -2;
		if(x >= allSum[n-1]) hasil = n-1;
		printf("Case #%d: %d\n", i + 1, hasil+1);
	}
}