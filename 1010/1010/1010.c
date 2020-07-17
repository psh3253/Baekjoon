#include <stdio.h>
long long Combination(int, int);
long long Permutation(int, int);
long long Factorial(int);

int main(void)
{
	int t, n, m, i;
	long long* result;
	scanf("%d", &t);
	result = (long long*)malloc(sizeof(long long) * t);

	for (i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		if (n <= 0 || n > m || m >= 30)
			return 0;
		result[i] = Combination(m, n);
	}
	for(i=0; i<t; i++)
		printf("%lld \n", result[i]);
	return 0;
}
long long Combination(int n, int r)
{
	return Permutation(n ,r) / Factorial(r);
}

long long Permutation(int n, int r)
{
	int i;
	long long result = 1;
	for (i = 0; i < r; i++)
	{
		result *= n;
		n--;
	}
	return result;
}

long long Factorial(int n)
{
	if (n <= 1)
		return 1;
	return n * Factorial(n - 1);
}