#include<stdio.h>

int value[400010];
long long int m;
long long int temp[400010];

long long int func(int cases){
	long long int max = 0, sum = 0;
	int i = cases, j = cases, k = 0;
	while(i >= 0)
{
		if(sum == m)
		{
			return sum;
		}
		else if(sum < m)
		{
			i--;
			k++;
			sum += (value[i]*k);
		}
		else
		{
			k--;
			sum -= (temp[i]-temp[j]);
			j--;
		}

		if(sum > max && sum <= m)
		{
			max = sum;
		}
	}
	return max;
}

int main(){

	int cases;
	scanf("%d", &cases);
	
	for(int i=0; i<cases; i++)
	{
		scanf("%d", &value[i]);
	}
	
	long long int sum = 0;
	for(int i = cases-1; i >= 0; i--){
		sum += value[i];
		temp[i] = sum;
	}
	
	scanf("%lld", &m);
	long long int hasil = func(cases);
	
	printf("%lld\n", hasil);
	
	return 0;
}