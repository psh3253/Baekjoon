#include <stdio.h>

int main(void)
{
	int num;

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = num; j > i + 1; j--)
		{
			printf(" ");
		}
		for (int k = 0; k < i + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}