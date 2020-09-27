#include <stdio.h>

int main(void)
{
	int n, m, i, j, k, max, temp, arr[100] = { 0, };
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	max = 0;
	for (i = 0; i < n - 2; i++)
	{
		for (j = i + 1; j < n - 1; j++)
		{
			for (k = j + 1; k < n; k++)
			{
				temp = arr[i] + arr[j] + arr[k];
				if (temp > max && temp <= m)
				{
					max = temp;
				}
			}
		}
	}
	printf("%d", max);
	return 0;
}