#include <iostream>
#include <vector>
using namespace std;

int bingo[9][9];
vector<pair<int, int>> zero;
bool visit[81];

bool is_promise(int r, int c, int num)
{
	for (int i = 0; i < 9; i++)
	{
		if (bingo[r][i] == num)
		{
			return false;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (bingo[i][c] == num)
		{
			return false;
		}
	}
	for (int i = (r / 3) * 3; i < (r / 3) * 3 + 3; i++)
	{
		for (int j = (c / 3) * 3; j < (c / 3) * 3 + 3; j++)
		{
			if (bingo[i][j] == num)
				return false;
		}
	}
	return true;
}

void backtracking(int r, int n)
{
	if (r == n)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				printf("%d", bingo[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	int y = zero[r].first;
	int x = zero[r].second;
	if (bingo[y][x] == 0)
	{
		for (int k = 1; k < 10; k++)
		{
			if (!is_promise(y, x, k))
				continue;
			bingo[y][x] = k;
			backtracking(r + 1, n);
			bingo[y][x] = 0;
		}
	}
}

int main(void)
{
	int zero_count = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%1d", &bingo[i][j]);
			if (bingo[i][j] == 0)
			{
				zero.push_back({ i, j });
				zero_count++;
			}
		}
	}
	backtracking(0, zero_count);
}