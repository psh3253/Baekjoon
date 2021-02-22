#include <iostream>
using namespace std;

int triangle[501][501];
int dp[501][501];

int getMax(int N, int M, int height)
{
	if (N == height)
		return dp[N][M] = triangle[N][M];
	if (dp[N][M] != 0)
		return dp[N][M];
	return dp[N][M] = max(getMax(N + 1, M, height) + triangle[N][M], getMax(N + 1, M + 1, height) + triangle[N][M]);
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> triangle[i][j];
		}
	}
	cout << getMax(1, 1, n) << endl;
}