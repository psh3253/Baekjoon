#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> wire[100];
int dp[101];

int getCount(int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (wire[j].second < wire[i].second)
				dp[i] = max(dp[j] + 1, dp[i]);
		}
		result = max(dp[i], result);
	}
	return n - result;
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> wire[i].first >> wire[i].second;
	}
	sort(wire, wire + n);
	cout << getCount(n) << endl;
}