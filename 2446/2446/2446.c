#include <stdio.h>

int main(void)
{
	int num, i, j;
	scanf("%d", &num);
	if (num < 1 || num > 100)
	{
		return 0;
	}
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * num - 1 - 2* i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i < num; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 1 + 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}