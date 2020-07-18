#include <stdio.h>

int main(void)
{
	int t, i, r, j, k;
	scanf("%d", &t);
	if (t < 1 || t>1000)
		return 0;
	for (i = 0; i < t; i++)
	{
		char s[20];
		k = 0;
		scanf("%d %s", &r, s);
		while (s[k] != NULL)
		{
			for (j = 0; j < r; j++)
			{
				printf("%c", s[k]);
			}
			k++;
		}
		printf("\n");
	}
	return 0;
}