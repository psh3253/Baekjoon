#include <stdio.h>

int main(void)
{
	int H, M;

	scanf("%d %d", &H, &M);
	if (M < 45)
	{
		if (H == 0)
		{
			H = 23;
		}
		else
		{
			H--;
		}
		M = M + 15;
	}
	else
	{
		M = M - 45;
	}
	printf("%d %d", H, M);
	return 0;
}