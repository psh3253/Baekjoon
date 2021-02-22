#include <iostream>
using namespace std;

int dp[1000001];

int getMin(int N)
{
	if (N == 1)
		return 0;
	else if (N % 3 == 0 && N % 2 == 0)
	{
		if (dp[N] != 0)
			return dp[N];
		return min(getMin(N / 3) + 1, min(getMin(N / 2) + 1, getMin(N - 1) + 1));
	}
	else if (N % 3 == 0)
	{
		if (dp[N] != 0)
			return dp[N];
		return dp[N] = min(getMin(N / 3) + 1, getMin(N - 1) + 1);
	}
	else if (N % 2 == 0)
	{
		if (dp[N] != 0)
			return dp[N];
		return dp[N] = min(getMin(N / 2) + 1, getMin(N - 1) + 1);
	}
	else
	{
		if (dp[N] != 0)
			return dp[N];
		return dp[N] = getMin(N - 1) + 1;
	}
}

int main(void)
{
	int N;
	cin >> N;
	cout << getMin(N) << endl;
}