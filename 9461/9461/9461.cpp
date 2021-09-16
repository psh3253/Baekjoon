#include <iostream>
using namespace std;
long long dp[101];

long long sequence(int n)
{
	if (n == 1)
		return dp[n] = 1;
	else if (n == 2)
		return dp[n] = 1;
	else if (n == 3)
		return dp[n] = 1;
	else
	{
		if (dp[n])
			return dp[n];
		return dp[n] = sequence(n - 2) + sequence(n - 3);
	}
}

int main(void)
{
	int T, N;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> N;
		sequence(N);
		cout << dp[N] << "\n";
	}
}