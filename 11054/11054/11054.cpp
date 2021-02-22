#include <iostream>
using namespace std;

int sequence[1000];
int dp[1000][2];

int length(int N)
{
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		dp[i][0] = 1;
		for (int j = 0; j < i; j++)
		{
			if (sequence[j] < sequence[i])
			{
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
			}
		}
	}
	for (int i = N - 1; i >= 0; i--)
	{
		dp[i][1] = 1;
		for (int j = N - 1; j > i; j--)
		{
			if (sequence[i] > sequence[j])
			{
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			}
		}
	}
	for (int i = 0; i < N; i++)
		result = max(result, dp[i][0] + dp[i][1] - 1);
	return result;
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> sequence[i];
	}
	cout << length(N) << endl;
}