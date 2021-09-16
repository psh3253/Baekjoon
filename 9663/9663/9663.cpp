#include <iostream>
using namespace std;
bool board[15][15];
int N, way_count;

bool isPromising(int length, int i)
{
	if (length > 0)
	{
		for (int j = 0; j < length; j++)
		{
			int dx = length - j;
			if (i == 0)
			{
				if (board[j][i] || board[j][i + dx])
					return false;
			}
			else if (i == N - 1)
			{
				if (board[j][i] || board[j][i - dx])
					return false;
			}
			else
			{
				if (board[j][i] || (i - dx > -1 && board[j][i - dx]) || (i + dx < N && board[j][i + dx]))
					return false;
			}
		}
		return true;
	}
	return true;
}

void dfs(int length)
{
	if (length == N)
	{
		way_count++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (isPromising(length, i)) {
			board[length][i] = true;
			dfs(length + 1);
			board[length][i] = false;
		}
	}
}

int main(void)
{
	cin >> N;
	dfs(0);
	cout << way_count << endl;
}