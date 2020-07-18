#include <stdio.h>

int main(void)
{
	int testcase, i, j, continuity, sum;
	scanf("%d", &testcase);
	for (i = 0; i < testcase; i++)
	{
		char ox[80];
		j = 0, continuity = 0, sum = 0;
		scanf("%s", ox);
		while (ox[j] != NULL)
		{
			if (ox[j] == 'O')
			{
				continuity++;
				sum += continuity;
			}
			else if(ox[j] == 'X')
				continuity = 0;
			j++;
		}
		printf("%d \n", sum);
	}
	return 0;
}