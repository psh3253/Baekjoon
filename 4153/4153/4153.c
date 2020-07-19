#include <stdio.h>

int main(void)
{
	int x, y, z;
	while (1)
	{
		scanf("%d %d %d", &x, &y, &z);
		if (x == 0 && y == 0 && z == 0)
			break;
		if (x * x + y * y == z * z || x * x + z * z == y * y || y * y + z * z == x * x)
			printf("right \n");
		else
			printf("wrong \n");
	}
	return 0;
}