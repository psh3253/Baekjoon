#include <iostream>
#include <algorithm>
using namespace std;
int A[1001];
int dp[1001];

int main(void)
{
	int N, result = 0;
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> A[i];
	}
	for (int i = 1; i < N + 1; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (A[j] < A[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		result = max(dp[i], result);
	}
	cout << result << "\n";
}