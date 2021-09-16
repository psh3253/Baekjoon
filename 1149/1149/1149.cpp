#include <iostream>
#include <algorithm>
using namespace std;
int cost[1001][3];
int dp[1001][3];

int getMin(int n, int rgb)
{
	if (n == 1)
	{
		return dp[n][rgb] = cost[n][rgb];
	}
	else
	{
		if (dp[n][rgb])
			return dp[n][rgb];
		if (rgb == 0)
		{
			return dp[n][rgb] = min(cost[n][rgb] + getMin(n - 1, 1), cost[n][rgb] + getMin(n - 1, 2));
		}
		else if(rgb == 1)
		{
			return dp[n][rgb] = min(cost[n][rgb] + getMin(n - 1, 0), cost[n][rgb] + getMin(n - 1, 2));
		}
		else
		{
			return dp[n][rgb] = min(cost[n][rgb] + getMin(n - 1, 0), cost[n][rgb] + getMin(n - 1, 1));
		}
	}
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	getMin(N, 0);
	getMin(N, 1);
	getMin(N, 2);
	cout << min({ dp[N][0], dp[N][1], dp[N][2]}) << "\n";
}