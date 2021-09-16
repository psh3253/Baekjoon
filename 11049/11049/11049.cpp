#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int matrix[501][2];
long long dp[501][501];

int main(void)
{
	int N;
	int r, c;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> r >> c;
		matrix[i][0] = r;
		matrix[i][1] = c;
	}
	for(int j = 1; j < N; j++)
	{
		for(int i = 0; i + j < N; i++)
		{
			dp[i][i + j] = INF;
			for(int k = i; k < i + j; k++)
			{
				dp[i][i + j] = min(dp[i][i + j], dp[i][k] + dp[k + 1][i + j] + matrix[i][0] * matrix[k][1] * matrix[i + j][1]);
			}
		}
	}
	cout << dp[0][N - 1] << '\n';
}