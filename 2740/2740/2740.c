#include <stdio.h>

int main(void)
{
	int n1, m1, n2, m2, i, j, k, l, A[100][100] = { 0, }, B[100][100] = { 0, }, sum;

	// ��� A �Է¹ޱ�
	scanf("%d %d", &n1, &m1);
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < m1; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	//��� B �Է¹ޱ�
	scanf("%d %d", &n2, &m2);
	for (i = 0; i < n2; i++)
	{
		for (j = 0; j < m2; j++)
		{
			scanf("%d", &B[i][j]);
		}
	}

	// ������ ��� ���
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < m2; j++)
		{
			sum = 0;
			for (k = 0; k < m1; k++)
			{
				sum += A[i][k] * B[k][j];
			}
			printf("%d ", sum);
		}
		printf("\n");
	}

	return 0;
}