#include <stdio.h>

int main ()
{
	long long int data = 0;
    long long int arr[100000];
    int result  = 0;
	scanf ("%lld", &data);
	long long int arr[data]={};
	for (int i = 0; i < data; i++){
		scanf ("%lld", &arr[i]);
        result = result + arr[i];
	}
	if (result % 2!=0)
	{
		for (int j=0;j<data;j++)
		{
			if (arr[j] % 2 !=0 )
            {
				result = result - arr[j];
			break;
			}
		}
	}
	printf ("%lld\n", result) ;
	return 0;
}