#include <stdio.h>

int main(void)
{
	int num, reverse_num, temp;

	while (1)
	{
		scanf("%d", &num);
		temp = num;
		reverse_num = 0;
		if (num == 0)
			break;
		while (num > 0)
		{
			reverse_num *= 10;
			reverse_num += num % 10;
			num /= 10;
		}
		if (temp == reverse_num)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}