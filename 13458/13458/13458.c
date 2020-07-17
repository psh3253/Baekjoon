#include <stdio.h>

int main(void)
{
	int n, b, c, i;
	long long sum = 0;
	int* a;
	scanf("%d", &n);
	if (n < 1 || n > 1000000)
	{
		return 0;
	}
	a = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < 1 || a[i] > 1000000)
		{
			return 0;
		}
	}
	scanf("%d %d", &b, &c);
	if (b < 1 || b > 1000000 || c < 1 || b > 1000000)
	{
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		sum++;
		a[i] -= b;
		if (a[i] > 0)
		{
			if (a[i] % c == 0)
			{
				sum += (long long)(a[i] / c);
			}
			else
			{
				sum += (long long)(a[i] / c) + 1;
			}
		}
	}
	printf("%lld", sum);
	free(a);
	return 0;
}