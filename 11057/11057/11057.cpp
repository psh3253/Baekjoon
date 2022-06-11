#include <iostream>
using namespace std;
int memo[1001][11];

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i < 11; i++)
		memo[1][i] = i;
	for(int i = 2; i < N + 1; i++)
	{
		for (int j = 1; j < 11; j++)
			memo[i][j] = (memo[i - 1][j] + memo[i][j - 1]) % 10007;
	}
	cout << memo[N][10] << '\n';
}