#include <stdio.h>

int main(void)
{
	int t, w, h, n, i, j, k, a, b;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		int a = 1, b = 1;
		scanf("%d %d %d", &h, &w, &n);
		int** hotel = (int**)malloc(sizeof(int*) * h);
		for (i = 0; i < h; i++)
		{
			hotel[i] = (int*)malloc(sizeof(int) * w);
		}
		for (j = 0; j < h; j++)
		{
			for (k = 0; k < w; k++)
			{
				hotel[j][k] = 100 * (j + 1) + (k + 1);
			}
		}
		for (i = 0; i < n; i++)
		{
			if (a % h == 1)
			{
				a = 1;
				b++;
			}
			a++;
		}
		printf("%d \n", 100 * a + b);
	}
	return 0;
}