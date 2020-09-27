#include <stdio.h>

int main(void)
{
	int x, y, w, h, i, least = 1000;
	int length[4];
	scanf("%d %d %d %d", &x, &y, &w, &h);
	length[0] = x;
	length[1] = y;
	length[2] = w - x;
	length[3] = h - y;
	for (i = 0; i < 4; i++)
	{
		if (least > length[i])
			least = length[i];
	}
	printf("%d", least);
	return 0;
}