#include <iostream>
using namespace std;
int star[5000][5000];

void set_star(int r, int c, int n)
{
	if(n == 1)
	{
		star[r][c] = 1;
		return;
	}
	set_star(r, c, n / 3);
	set_star(r, c + n / 3, n / 3);
	set_star(r, c + 2 * n / 3, n / 3);
	set_star(r + n / 3, c, n / 3);
	set_star(r + n / 3, c + 2 * n / 3, n / 3);
	set_star(r + 2 * n / 3, c, n / 3);
	set_star(r + 2 * n / 3, c + n / 3, n / 3);
	set_star(r + 2 * n / 3, c + 2 * n / 3, n / 3);
}

int main(void)
{
	int N;
	cin >> N;
	set_star(0, 0, N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if (star[i][j])
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
}