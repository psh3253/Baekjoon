#include <stdio.h>

int main(void)
{
	char str[101], matrix[100][100];
	int i, j, k = 0, r = 0, c = 0, count = 0;

	// 문자열 입력 받기
	scanf("%s", str);
	while (str[count] != '\0')
	{
		count++;
	}

	// 행과 열 구하기
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

	// 행렬에 문자열 대입
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < r; j++)
		{
			matrix[j][i] = str[k];
			k++;
		}
	}

	// 행렬에 저장된 문자열 전치 상태로 출력
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%c", matrix[i][j]);
		}
	}
	return 0;
}