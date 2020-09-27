#include <stdio.h>

int main(void)
{
	int n, m, count = 0;
	scanf("%d", &n);
	m = n;
	count += n / 5;
	n %= 5;
	while (n % 3 != 0)
	{
		if (count == 0)
		{
			printf("-1");
			return 0;
		}
		n += 5;
		count--;
	}
	count += n / 3;
	printf("%d", count);
	return 0;
}