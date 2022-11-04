#include <iostream>
using namespace std;

int arr[100][100];
long long dp[100][100];

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == N - 1 && j == N - 1)
				break;
			if (arr[i][j] + i < N)
				dp[arr[i][j] + i][j] += dp[i][j];
			if (arr[i][j] + j < N)
				dp[i][arr[i][j] + j] += dp[i][j];
		}
	}

	cout << dp[N - 1][N - 1] << '\n';
}