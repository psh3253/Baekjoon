#include <stdio.h>

int main(void)
{
	int ham[3], dri[2], i, cheapHam = 2000, cheapDri = 2000;
	for (i = 0; i < 3; i++)
		scanf("%d", &ham[i]);
	for (i = 0; i < 2; i++)
		scanf("%d", &dri[i]);
	for (i = 0; i < 3; i++)
	{
		if (ham[i] < cheapHam)
			cheapHam = ham[i];
	}
	for (i = 0; i < 2; i++)
	{
		if (dri[i] < cheapDri)
			cheapDri = dri[i];
	}
	printf("%d", cheapDri + cheapHam - 50);
	return 0;
}