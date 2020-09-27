#include <stdio.h>

int A[50][50], B[50][50];
void reverse(int, int);

int main(void)
{
	int n, m, i, j, count = 0;

	// ����� ũ�� �Է�
	scanf("%d %d", &n, &m);

	// ��� A �Է�
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%1d", &A[i][j]);
		}
	}

	// ��� B �Է�
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%1d", &B[i][j]);
		}
	}

	// ������
	for (i = 0; i < n - 2; i++)
	{
		for (j = 0; j < m - 2; j++)
		{
			if (A[i][j] != B[i][j])
			{
				reverse(i, j);
				count++;
			}
		}
	}

	// Ȯ��
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (A[i][j] != B[i][j])
			{
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", count);
	return 0;
}

// A ��� ������ �Լ�
void reverse(int i, int j)
{
	int r, c;
	for (r = i; r <= i + 2; r++)
	{
		for (c = j; c <= j + 2; c++)
		{
			if (A[r][c] == 1)
				A[r][c] = 0;
			else
				A[r][c] = 1;
		}
	}
}