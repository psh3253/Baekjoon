#include <iostream>
using namespace std;
long long dp[101];

int main(void)
{
	int n, p;
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p);
		if (dp[p] != 0)
		{
			printf("%lld\n", dp[p]);
		}
		else
		{
			for (int i = 4; i < p + 1; i++)
			{
				if (dp[i] != 0)
					continue;
				dp[i] = dp[i - 3] + dp[i - 2];
			}
			printf("%lld\n", dp[p]);
		}
	}
	return 0;
}