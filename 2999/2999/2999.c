#include <stdio.h>

int main(void)
{
	char str[101], matrix[100][100];
	int i, j, k = 0, r = 0, c = 0, count = 0;

	// ���ڿ� �Է� �ޱ�
	scanf("%s", str);
	while (str[count] != '\0')
	{
		count++;
	}

	// ��� �� ���ϱ�
	for (i = 1; i <= count; i++)
	{
		for (j = 1; j <= count; j++)
		{
			if (i * j == count)
			{
				if (i <= j)
				{
					r = i;
					c = j;
				}
			}
		}
	}

	// ��Ŀ� ���ڿ� ����
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < r; j++)
		{
			matrix[j][i] = str[k];
			k++;
		}
	}

	// ��Ŀ� ����� ���ڿ� ��ġ ���·� ���
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%c", matrix[i][j]);
		}
	}
	return 0;
}