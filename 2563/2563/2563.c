#include <stdio.h>

int main(void)
{
	int drawingPaper[100][100] = { 0, }, n, i, j, k, x, y, count = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		// �����̸� ���� ��ȭ���� ��ǥ ����
		scanf("%d %d", &x, &y);

		// ��ȭ���� �����̸� ���̱�
		for (j = 0; j < 10; j++)
		{
			for (k = 0; k < 10; k++)
			{
				drawingPaper[x + j][y + k] = 1;
			}
		}
	}

	// ��ȭ������ �����̰� ���� �κ� ���� ��������
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (drawingPaper[i][j] == 1)
				count++;
		}
	}
	printf("%d", count);
	return 0;
}