#include <iostream>
#include <algorithm>
using namespace std;
int sequence[1001];
int dp[1001];
int dp2[1001];

int main(void)
{
	int N;
	int result = 0;
	cin >> N;
	for(int i = 0; i< N; i++)
	{
		cin >> sequence[i];
	}
	for(int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for(int j = 0; j < i; j++)
		{
			if (sequence[j] < sequence[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	for(int i = N - 1; i > -1; i--)
	{
		dp2[i] = 1;
		for(int j = N - 1; j > i; j--)
		{
			if (sequence[j] < sequence[i])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}
	for(int i = 0; i < N; i++)
	{
		result = max(result, dp[i] + dp2[i] - 1);
	}
	cout << result << "\n";
}