#include <iostream>
using namespace std;
bool star[3072][6143];

void make_star(int n, int r, int c)
{
	if (n == 3)
	{
		star[r][c] = true;
		star[r + 1][c - 1] = true;
		star[r + 1][c + 1] = true;
		star[r + 2][c - 2] = true;
		star[r + 2][c - 1] = true;
		star[r + 2][c] = true;
		star[r + 2][c + 1] = true;
		star[r + 2][c + 2] = true;
		return;
	}
	make_star(n / 2, r, c);
	make_star(n / 2, r + n / 2, c - n / 2);
	make_star(n / 2, r + n / 2, c + n / 2);
}

int main(void)
{
	int N;
	cin >> N;
	make_star(N, 0, N - 1);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < 2 * N - 1; j++)
		{
			if (star[i][j])
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
}