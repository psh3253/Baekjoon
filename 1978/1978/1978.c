#include <stdio.h>

int main(void)
{
	int n, i, j, isPrimeNumber, count = 0, arr[100] = { 0, };
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		isPrimeNumber = 1;
		if (arr[i] == 1)
			isPrimeNumber = 0;
		for (j = 2; j < arr[i]; j++)
		{
			if (arr[i] % j == 0)
				isPrimeNumber = 0;
		}
		if (isPrimeNumber)
			count++;
	}
	printf("%d", count);
	return 0;
}