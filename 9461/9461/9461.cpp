#include <iostream>
using namespace std;

long long dp[101];

long long sequence(int N)
{
	if (N == 1 || N == 2 || N == 3)
		return dp[N] = 1;
	else
	{
		if (dp[N] != 0)
			return dp[N];
		return dp[N] = sequence(N - 2) + sequence(N - 3);
	}
}

int main(void)
{
	int T;
	int N;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << sequence(N) << "\n";
	}
}