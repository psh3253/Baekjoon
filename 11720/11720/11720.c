#include <stdio.h>

int main(void)
{
	int n, i, sum = 0;
	char num[100];
	scanf("%d", &n);
	scanf("%s", num);
	for (i = 0; i < n; i++)
	{
		sum += (num[i] - 48);
	}
	printf("%d", sum);
	return 0;
}