#include <iostream>
using namespace std;

int cost[1001][3];
int dp[1001][3];

int getMin(int N, int RGB)
{
	if (N == 1)
		return dp[1][RGB] = cost[1][RGB];
	else
	{
		if (dp[N][RGB] != 0)
			return dp[N][RGB];
		if (RGB == 0)
			return dp[N][RGB] = min(getMin(N - 1, 1) + cost[N][RGB], getMin(N - 1, 2) + cost[N][RGB]);
		else if (RGB == 1)
			return dp[N][RGB] = min(getMin(N - 1, 0) + cost[N][RGB], getMin(N - 1, 2) + cost[N][RGB]);
		else
			return dp[N][RGB] = min(getMin(N - 1, 0) + cost[N][RGB], getMin(N - 1, 1) + cost[N][RGB]);
	}
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	cout << min(getMin(N, 0), min(getMin(N, 1), getMin(N, 2))) << "\n";
}