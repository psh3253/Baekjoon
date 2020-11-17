#include <iostream>
using namespace std;
int dp[1000001];

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main(void)
{
	int N;
	cin >> N;
	dp[1] = 0;
	for (int i = 2; i < N + 1; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	cout << dp[N] << endl;
}