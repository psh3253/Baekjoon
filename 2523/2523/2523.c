#include <stdio.h>

int main(void)
{
	int i, j, k, n;
	scanf("%d", &n);
	for (i = 0; i < n * 2 - 1; i++)
	{
		if (i < n)
		{
			for (j = 0; j < i + 1; j++)
			{
				printf("*");
			}
		}
		else
		{
			for (k = i; k < n * 2 -1; k++)
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}