#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];
int min_dp[3];
int max_dp[3];

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> arr[0] >> arr[1] >> arr[2];
		int min_dp_first = min_dp[0];
		int min_dp_second = min_dp[1];
		int min_dp_third = min_dp[2];
		int max_dp_first = max_dp[0];
		int max_dp_second = max_dp[1];
		int max_dp_third = max_dp[2];
		max_dp[0] = max(max_dp_first, max_dp_second) + arr[0];
		max_dp[1] = max({ max_dp_first, max_dp_second, max_dp_third }) + arr[1];
		max_dp[2] = max(max_dp_second, max_dp_third) + arr[2];
		min_dp[0] = min(min_dp_first, min_dp_second) + arr[0];
		min_dp[1] = min({ min_dp_first, min_dp_second, min_dp_third }) + arr[1];
		min_dp[2] = min(min_dp_second, min_dp_third) + arr[2];
	}
	cout << max({ max_dp[0], max_dp[1], max_dp[2] }) << " ";
	cout << min({ min_dp[0], min_dp[1], min_dp[2] }) << '\n';
}