#include <stdio.h>
using namespace std;
int	arr[501][501];
long long dp[501][501];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	return 0;
}