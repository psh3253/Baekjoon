#include <iostream>
using namespace std;
int arr[1001];
int dp[1001];

int main(void)
{
	int answer = 0;
	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < n + 1; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
		answer = max(answer, dp[i]);
	}
	cout << answer << '\n';
}