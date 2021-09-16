#include <iostream>
using namespace std;
int paper[3000][3000];
int a_count, b_count, c_count;

void slice(int x, int y, int N)
{
	int check = paper[y][x];
	for (int i = y; i < y + N; i++)
	{
		for (int j = x; j < x + N; j++)
		{
			if (check != paper[i][j])
			{
				slice(x, y, N / 3);
				slice(x + N / 3, y, N / 3);
				slice(x + 2 * N / 3, y, N / 3);
				slice(x, y + N / 3, N / 3);
				slice(x, y + 2 * N / 3, N / 3);
				slice(x + N / 3, y + N / 3, N / 3);
				slice(x + 2 * N / 3, y + N / 3, N / 3);
				slice(x + N / 3, y + 2 * N / 3, N / 3);
				slice(x + 2 * N / 3, y + 2 * N / 3, N / 3);
				return;
			}
		}
	}
	if (check == -1)
		a_count++;
	else if (check == 0)
		b_count++;
	else
		c_count++;
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> paper[i][j];
		}
	}
	slice(0, 0, N);
	cout << a_count << '\n';
	cout << b_count << '\n';
	cout << c_count << '\n';
}