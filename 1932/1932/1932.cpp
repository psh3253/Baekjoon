#include <iostream>
#include <algorithm>
using namespace std;
int n;
int mountain[501][501];
int dp[501][501];

int getMax(int height, int width)
{
	if (height == n)
		return dp[height][width] = mountain[height][width];
	else
	{
		if (dp[height][width])
			return dp[height][width];
		return dp[height][width] = max(mountain[height][width] + getMax(height + 1, width), mountain[height][width] + getMax(height + 1, width + 1));
	}
}

int main(void)
{
	cin >> n;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			cin >> mountain[i][j];
		}
	}
	getMax(1, 1);
	cout << dp[1][1] << "\n";
}