#include <iostream>
using namespace std;

long long dp[10001];
long long fibonacci(int n)
{
	if (n == 1)
		return dp[1];
	else if (n == 2)
		return dp[2];
	else
	{
		if (dp[n] != 0)
			return dp[n];
		return dp[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % 10007;
	}
}

int main(void)
{
	int n;
	dp[1] = 1;
	dp[2] = 2;
	cin >> n;
	cout << fibonacci(n)<< endl;
}