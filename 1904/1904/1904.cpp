#include <iostream>
using namespace std;
int dp[1000001];
int sequence(int n)
{
	if (n == 1)
		return dp[n] = 1;
	else if (n == 2)
		return dp[n] = 2;
	else
	{
		if (dp[n])
			return dp[n];
		return dp[n] = (sequence(n - 1) + sequence(n - 2)) % 15746;
	}
}

int main(void)
{
	int N;
	cin >> N;
	sequence(N);
	cout << dp[N] << "\n";
}