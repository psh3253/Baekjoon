#include <iostream>
#include <utility>
#include <vector>
using namespace std;
vector<pair<int, int>> blank;
int board[9][9];

bool isPromise(int y, int x)
{
	int num = board[y][x];
	for (int i = 0; i < 9; i++)
	{
		if ((y != i && board[i][x] == num) || (x != i && board[y][i] == num))
			return false;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (x % 3 == 0)
			{
				if (y % 3 == 0)
				{
					if (i != 0 && j != 0 && board[y + i][x + j] == num)
						return false;
				}
				else if (y % 3 == 1)
				{
					if (i - 1 != 0 && j != 0 && board[y - 1 + i][x + j] == num)
						return false;
				}
				else
				{
					if (i - 2 != 0 && j != 0 && board[y - 2 + i][x + j] == num)
						return false;
				}
			}
			else if (x % 3 == 1)
			{
				if (y % 3 == 0)
				{
					if (i != 0 && j - 1 != 0 && board[y + i][x - 1 + j] == num)
						return false;
				}
				else if (y % 3 == 1)
				{
					if (i - 1 != 0 && j - 1 != 0 && board[y - 1 + i][x - 1 + j] == num)
						return false;
				}
				else
				{
					if (i - 2 != 0 && j - 1 != 0 && board[y - 2 + i][x - 1 + j] == num)
						return false;
				}
			}
			else
			{
				if (y % 3 == 0)
				{
					if (i != 0 && j - 2 != 0 && board[y + i][x - 2 + j] == num)
						return false;
				}
				else if (y % 3 == 1)
				{
					if (i - 1 != 0 && j - 2 != 0 && board[y - 1 + i][x - 2 + j] == num)
						return false;
				}
				else
				{
					if (i - 2 != 0 && j - 2 != 0 && board[y - 2 + i][x - 2 + j] == num)
						return false;
				}
			}
		}
	}
	return true;
}

void dfs(int length)
{
	if (length == blank.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	for (int i = 1; i < 10; i++)
	{
		board[blank[length].first][blank[length].second] = i;
		if (isPromise(blank[length].first, blank[length].second))
			dfs(length + 1);
		board[blank[length].first][blank[length].second] = 0;
	}
}

int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
				blank.push_back(make_pair(i, j));
		}
	}
	dfs(0);
}