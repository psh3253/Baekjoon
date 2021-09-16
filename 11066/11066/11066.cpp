#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int file[501];
int dp[501][501];
int sum[501];

int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int K;
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			cin >> file[j];
			sum[j + 1] = sum[j] + file[j];
		}
		for (int j = 1; j < K; j++)
		{
			for (int m = 0; j + m < K; m++)
			{
				dp[m][m + j] = INF;
				for (int n = m; n < m + j; n++)
				{
					dp[m][m + j] = min(dp[m][m + j], dp[m][n] + dp[n + 1][m + j] + sum[m + j + 1] - sum[m]);
				}
			}
		}
		cout << dp[0][K - 1] << '\n';
	}
}