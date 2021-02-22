#include <iostream>
using namespace std;

int dp[1000001];

int sequence(int N)
{
	if (N == 1)
		return dp[1] = 1;
	else if (N == 2)
		return dp[2] = 2;
	else
	{
		if (dp[N] != 0)
			return dp[N];
		return dp[N] = (sequence(N - 1) + sequence(N - 2)) % 15746;
	}
}

int main(void)
{
	int N;
	cin >> N;
	cout << sequence(N) << endl;
}