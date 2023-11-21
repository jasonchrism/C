#include <stdio.h>

int main()
{

	int day;
	scanf("%d", &day);
	int view[150];
	int teman, a, b;

	for (int i = 0; i < day; i++)
	{
		scanf("%d", &view[i]);
	}

	scanf("%d", &teman);
	for (int i = 0; i < teman; i++)
	{
		scanf("%d%d", &a, &b);
		printf("Case #%d:\n", i + 1);
		int sum = 0;
		for (int j = a - 1; j <= b - 1; j++)
		{
			sum = sum + view[j];
		}
		printf("%d\n", sum);
	}
}
