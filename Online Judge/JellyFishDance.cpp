#include <stdio.h>

int main()
{

	int day, views, friends, a, b;
	scanf("%d", &day);
	int viewDay[day];

	for (int i = 0; i < day; i++)
	{
		scanf("%d", &views);
		viewDay[i] = views;
	}

	scanf("%d", &friends);
	int n[friends] = {};
	for (int k = 0; k < friends; k++)
	{
		scanf("%d%d", &a, &b);
		for (int j = 0; j < day; j++)
		{
			if (a <= j + 1 && j + 1 <= b)
			{
				n[k] += viewDay[j];
			}
		}
	}

	for (int i = 0; i < friends; i++)
	{
		printf("Case #%d: %d\n", i + 1, n[i]);
	}
}
