#include <iostream>
using namespace std;

int dp[41];

int fibonacci(int N)
{
	if (N == 0)
		return 0;
	else if (N == 1)
		return 1;
	else
	{
		if (dp[N] != 0)
			return dp[N];
		else
			return dp[N] = fibonacci(N - 1) + fibonacci(N - 2);
	}
}

int main(void)
{
	int T;
	int N;
	cin >> T;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		if (N == 0)
			cout << "1 0" << endl;
		else if (N == 1)
			cout << "0 1" << endl;
		else
		{
			fibonacci(N);
			cout << dp[N - 1] << " " << dp[N] << endl;
		}
	}
}