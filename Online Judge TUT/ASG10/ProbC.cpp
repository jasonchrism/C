#include <stdio.h>

int main (){
    
	int n;
	scanf ("%d", &n);
	int counter = 0;
	long long int key;
	long long int cust[n];
	for (int i = 0; i < n; i++)
	{
		int check = 1;
		scanf ("%lld", &key);
		for (int j=0; j<counter; j++)
		{
			if (key == cust[j]) check = 0;
		}
		if (check == 1)
		{
			cust[counter] = key;
			counter++;
		}
	}
	printf ("%d\n", counter);
}