#include <stdio.h>

int main(void)
{
	int c, i, j, n, sum, average, count;
	double rate;
	int* score;
	
	scanf("%d", &c);
	for (i = 0; i < c; i++)
	{
		sum = 0;
		count = 0;
		scanf("%d", &n);
		score = (int*)malloc(sizeof(int) * n);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &score[j]);
			sum += score[j];
		}
		average = sum / n;
		for (j = 0; j < n; j++)
		{
			if (score[j] > average)
				count++;
		}
		rate = (double)count / (double)n;
		printf("%.3lf\%%\n", rate * 100);
	}
	return 0;

}