#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int dp[101][10001];
int m[101];
int c[101];

int main(void)
{
	int N, M;
	int total_cost = 0;
	int result = INF;
	cin >> N >> M;
	for(int i = 1; i < N + 1; i++)
	{
		cin >> m[i];
	}
	for(int i = 1; i < N + 1; i++)
	{
		cin >> c[i];
		total_cost += c[i];
	}
	for(int i = 1; i < N + 1; i++)
	{
		for(int j = 0; j < total_cost + 1; j++)
		{
			if(j - c[i] >= 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + m[i]);
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
			else
			{
				dp[i][j] =  dp[i - 1][j];
			}
		}
	}
	for(int i = 0; i < total_cost + 1; i++)
	{
		if(dp[N][i] >= M)
			result = min(result, i);
	}
	cout << result << '\n';
}