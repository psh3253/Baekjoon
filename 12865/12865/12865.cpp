#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
int dp[101][100001];

pair<int, int> object[101];

int main(void)
{
	int N, K;
	cin >> N >> K;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> object[i].first >> object[i].second;
	}
	for(int i = 1; i < N + 1; i++)
	{
		for(int j = 1; j < K + 1; j++)
		{
			if(j - object[i].first >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - object[i].first] + object[i].second);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[N][K] << "\n";
}