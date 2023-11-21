#include <stdio.h>

int arr[110]={};

void solve(int first, int last, int sum)
{
	if(first*2>last){
		printf ("%d\n", sum);
		return; 
	}
	else{
		solve(first*2, last,sum+arr[first*2]);
	}
	if (first*2==last){
		return;
	}
	if(first*2+1>last){
		printf ("%d\n", sum);
		return;
	}
	else{
		solve(first*2+1, last, sum+arr[first*2+1]);
	}
	return;
}

int main ()
{
	int input;
	scanf ("%d", &input);
	for (int i=0; i<input; i++)
	{
		int lenght=0;   
		scanf ("%d", &lenght);
		for (int j=0; j<lenght; j++)
		{
			scanf ("%d", &arr[j+1]);
		}
		printf ("Case #%d:\n", i + 1);
		solve(1, lenght, arr[1]);
	}
	return 0;
}