#include <iostream>
#include <algorithm>
using namespace std;
int wine[10001];
int dp[10001];

void getMax(int n)
{
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	dp[3] = max({ wine[1] + wine[2], wine[1] + wine[3], wine[2] + wine[3] });
	for(int i = 4; i < n + 1; i++)
	{
		dp[i] = max({ wine[i] + dp[i - 2], wine[i] + wine[i - 1] + dp[i - 3], dp[i - 1] });
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++)
	{
		cin >> wine[i];
	}
	getMax(n);
	cout << dp[n] << "\n";
}