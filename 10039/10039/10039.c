#include <stdio.h>

int main(void)
{
	int stu[5], i, sum = 0;
	
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &stu[i]);
		if (stu[i] >= 40)
			sum += stu[i];
		else
			sum += 40;
	}
	printf("%d", sum / 5);
}