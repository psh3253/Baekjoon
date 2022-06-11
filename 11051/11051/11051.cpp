#include <iostream>
using namespace std;
int memo[1001][1001];

int main(void)
{
	int N, K;
	cin >> N >> K;
	for(int i = 1; i < N + 1; i++)
	{
		for(int j = 0; j < K + 1; j++)
		{
			if (i == j)
				memo[i][j] = 1;
			else if (j == 0)
				memo[i][j] = 1;
			else
				memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j]) % 10007;
		}
	}
	cout << memo[N][K] << '\n';
}