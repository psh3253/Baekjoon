#include <iostream>
using namespace std;
int paper[128][128];
int white_count, blue_count;

void slice(int x, int y, int N)
{
	int check = paper[x][y];
	for(int i = x; i < x + N; i++)
	{
		for(int j = y; j < y + N; j++)
		{
			if(check != paper[i][j])
			{
				slice(x, y, N / 2);
				slice(x + N / 2, y, N / 2);
				slice(x, y + N / 2, N / 2);
				slice(x + N / 2, y + N / 2, N / 2);
				return;
			}
		}
	}
	if (check)
		blue_count++;
	else
		white_count++;
	return;
}

int main(void)
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> paper[i][j];
		}
	}
	slice(0, 0, N);
	cout << white_count << '\n';
	cout << blue_count << '\n';
}