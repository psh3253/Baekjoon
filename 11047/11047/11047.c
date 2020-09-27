#include <stdio.h>

int main(void)
{
	int n, cost, i, count = 0;
	int coin[10];

	scanf("%d %d", &n, &cost);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);
	}

	for (i = n - 1; i >= 0; i--)
	{
		count += cost / coin[i];
		cost = cost % coin[i];
	}
	printf("%d\n", count);
	return 0;
}