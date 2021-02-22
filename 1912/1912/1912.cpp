#include <iostream>
using namespace std;

int sequence[100000];
int dp[100000];

int getMax(int n)
{
	int result = -1000;
	dp[0] = sequence[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + sequence[i], sequence[i]);
	}
	for (int i = 0; i < n; i++)
	{
		result = max(result, dp[i]);
	}
	return result;
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}
	cout << getMax(n) << endl;
}