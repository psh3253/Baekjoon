#include <stdio.h>

int main(void)
{
	int num;
	
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}