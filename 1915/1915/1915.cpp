#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1001][1001];
int dp[1001][1001];

int main(void)
{
	int answer = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (arr[i][j] == 0)
				dp[i][j] = 0;
			else
			{
				dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
				answer = max(answer, dp[i][j]);
			}
		}
	}
	cout << answer * answer << '\n';
}