#include <iostream>
using namespace std;

int score[301];
int dp[301];

int getMax(int N)
{
	if (N == 1)
		return dp[N] = score[1];
	else if (N == 2)
		return dp[N] = max(score[1] + score[2], score[2]);
	else if (N == 3)
		return dp[N] = max(score[2] + score[3], score[1] + score[3]);
	else
	{
		if (dp[N] != 0)
			return dp[N];
		return dp[N] = max(getMax(N - 2) + score[N], getMax(N - 3) + score[N - 1] + score[N]);
	}
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> score[i];
	}
	cout << getMax(N) << endl;
}