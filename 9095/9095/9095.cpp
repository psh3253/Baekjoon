#include <iostream>
using namespace std;
int dp[11];
void sum(int n)
{
	for (int i = 4; i < n + 1; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
}

int main(void)
{
	int T, n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int j = 4; j < n + 1; j++)
		{
			dp[j] = 0;
		}
		sum(n);
		cout << dp[n] << endl;
	}
}