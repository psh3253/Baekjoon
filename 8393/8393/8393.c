#include <stdio.h>

int main(void)
{
	int num, sum = 0;
	scanf("%d", &num);
	for (int i = 0; i < num + 1; i++)
	{
		sum = sum + i;
	}
	printf("%d", sum);
	return 0;
}