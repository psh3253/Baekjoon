#include <iostream>
using namespace std;

int wine[10001];
int dp[10001];

int getMax(int n)
{
	if (n == 1)
		return dp[n] = wine[n];
	else if (n == 2)
		return dp[n] = max(wine[2], max(wine[1] + wine[2], wine[1]));
	else if (n == 3)
		return dp[n] = max(wine[1] + wine[3], max(wine[2] + wine[3], wine[1] + wine[2]));
	else
	{
		if (dp[n] != 0)
			return dp[n];
		return dp[n] = max(getMax(n - 3) + wine[n - 1] + wine[n], max(getMax(n - 2) + wine[n], getMax(n - 1)));
	}
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> wine[i];
	}
	cout << getMax(n) << endl;
}