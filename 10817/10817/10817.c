#include <stdio.h>

int main(void)
{
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if (A > B)
	{
		if (A < C)
		{
			printf("%d", A);
		}
		else if (B > C)
		{
			printf("%d", B);
		}
		else
		{
			printf("%d", C);
		}
	}
	else if (A > C)
	{
		if (A < B)
		{
			printf("%d", A);
		}
		else if (B < C)
		{
			printf("%d", C);
		}
		else
		{
			printf("%d", B);
		}
	}
	else if(B > C)
	{
		if (A > B)
		{
			printf("%d", B);
		}
		else if (C > A)
		{
			printf("%d", C);
		}
		else
		{
			printf("%d", A);
		}
	}
	else
	{
		printf("%d", B);
	}
	return 0;
}