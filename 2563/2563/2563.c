#include <stdio.h>

int main(void)
{
	int drawingPaper[100][100] = { 0, }, n, i, j, k, x, y, count = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		// 색종이를 붙일 도화지의 좌표 설정
		scanf("%d %d", &x, &y);

		// 도화지에 색종이를 붙이기
		for (j = 0; j < 10; j++)
		{
			for (k = 0; k < 10; k++)
			{
				drawingPaper[x + j][y + k] = 1;
			}
		}
	}

	// 도화지에서 색종이가 붙은 부분 면적 가져오기
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