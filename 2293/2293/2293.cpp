#include <iostream>
#include <algorithm>
using namespace std;
int coin[101];
int dp[10001];

int main(void)
{
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}
	sort(coin, coin + n);
	dp[0] = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = coin[i]; j < k + 1; j++)
		{
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}
	cout << dp[k] << '\n';
}