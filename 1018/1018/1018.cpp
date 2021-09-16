#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	char board[50][50];
	int N, M, min_square_count = 64, square_count;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}
	for (int i = 0; i + 7 < N; i++)
	{
		for (int j = 0; j + 7 < M; j++)
		{
			square_count = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if ((i + k + j + l) % 2 == 0)
					{
						if (board[i + k][j + l] != 'B')
							square_count++;
					}
					else
					{
						if (board[i + k][j + l] != 'W')
							square_count++;
					}
				}
			}
			min_square_count = min(min_square_count, square_count);
			square_count = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if ((i + k + j + l) % 2 == 0)
					{
						if (board[i + k][j + l] != 'W')
							square_count++;
					}
					else
					{
						if (board[i + k][j + l] != 'B')
							square_count++;
					}
				}
			}
			min_square_count = min(min_square_count, square_count);
		}
	}
	cout << min_square_count << endl;
}