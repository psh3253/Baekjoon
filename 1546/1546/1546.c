#include <stdio.h>

int main(void)
{
	int num, i, max = 0;
	double subject[1000], sum = 0;

	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf("%lf", &subject[i]);
	}

	// �ִ� ã��
	for (i = 0; i < num; i++)
	{
		if (subject[i] > max)
			max = subject[i];
	}

	// �� ���ϱ�
	for (i = 0; i < num; i++)
	{
		subject[i] = subject[i] / max * 100;
		sum += subject[i];
	}

	printf("%lf", sum / num);
	return 0;
}