#include <iostream>
using namespace std;
int dp[41];

int fibonacci(int n)
{
	if (n == 0)
		return dp[0];
	else if (n == 1)
		return dp[1];
	if (dp[n])
		return dp[n];
	return dp[n] = fibonacci(n - 2) + fibonacci(n - 1);
}

int main(void)
{
	int T, N;
	cin >> T;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		fibonacci(N);
		if (N == 0)
			cout << "1 0" << "\n";
		else if (N == 1)
			cout << "0 1" << "\n";
		else
			cout << dp[N - 1] << " " << dp[N] << "\n";
	}
}