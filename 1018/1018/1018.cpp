#include <iostream>
using namespace std;
char board[50][50];
int minCount = 64;

void checkSquareCount(int y, int x)
{
	int temp = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((y + i + x + j) % 2 == 0)
			{
				if (board[y + i][x + j] != 'W')
					temp++;
			}
			else
			{
				if (board[y + i][x + j] != 'B')
					temp++;
			}
		}
	}
	minCount = min(minCount, temp);
	temp = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((y + i + x + j) % 2 == 0)
			{
				if (board[y + i][x + j] != 'B')
					temp++;
			}
			else
			{
				if (board[y + i][x + j] != 'W')
					temp++;
			}
		}
	}
	minCount = min(minCount, temp);
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}
	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			checkSquareCount(i, j);
		}
	}
	cout << minCount << endl;
}