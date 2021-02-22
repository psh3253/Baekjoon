#include <iostream>
using namespace std;

int sequence[1000];
int dp[1000];

int length(int N)
{
	int result = 1;
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (sequence[j] < sequence[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		result = max(result, dp[i]);
	}
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