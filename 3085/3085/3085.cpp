#include <iostream>
using namespace std;
char board[50][50];
int maxCount, N;

void checkCandyCount()
{
	for (int i = 0; i < N; i++)
	{
		int temp = 1;
		for (int j = 1; j < N; j++)
		{
			if (board[i][j] == board[i][j - 1])
				temp++;
			else
			{
				maxCount = max(maxCount, temp);
				temp = 1;
			}
		}
		maxCount = max(maxCount, temp);
	}
	for (int i = 0; i < N; i++)
	{
		int temp = 1;
		for (int j = 1; j < N; j++)
		{
			if (board[j][i] == board[j - 1][i])
				temp++;
			else
			{
				maxCount = max(maxCount, temp);
				temp = 1;
			}
		}
		maxCount = max(maxCount, temp);
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			swap(board[i][j], board[i][j + 1]);
			checkCandyCount();
			swap(board[i][j], board[i][j + 1]);
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			swap(board[i][j], board[i + 1][j]);
			checkCandyCount();
			swap(board[i][j], board[i + 1][j]);
		}
	}
	cout << maxCount << endl;
}