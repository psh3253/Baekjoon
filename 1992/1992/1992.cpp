#include <iostream>
using namespace std;
int video[64][64];
string result = "";

void compress(int x, int y, int N)
{
	int check = video[y][x];
	for(int i = y; i < y + N; i++)
	{
		for(int j = x; j < x + N; j++)
		{
			if(check != video[i][j])
			{
				result.append("(");
				compress(x, y, N / 2);
				compress(x + N / 2, y, N / 2);
				compress(x, y + N / 2, N / 2);
				compress(x + N / 2, y + N / 2, N / 2);
				result.append(")");
				return;
			}
		}
	}
	if(check)
	{
		result.append("1");
	}
	else
	{
		result.append("0");
	}
	return;
}

int main(void)
{
	int N;
	int temp;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0 ; j < N; j++)
		{
			scanf("%1d", &video[i][j]);
		}
	}
	compress(0, 0, N);
	cout << result << '\n';
}