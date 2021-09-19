#include <iostream>
using namespace std;
int num[2001];
bool dp[2001][2001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N;
	for(int i = 1; i < N + 1; i++)
	{
		cin >> num[i];
		dp[i][i] = true;
		if(i > 1)
		{
			if(num[i - 1] == num[i])
			{
				dp[i - 1][i] = true;
			}
		}
	}
	for(int i = 2; i < N; i++)
	{
		for(int j = 1; j + i < N + 1; j++)
		{
			if(dp[j + 1][j + i -1] && num[j] == num[j+ i])
			{
				dp[j][j + i] = true;
			}
		}
	}
	
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		if (dp[S][E])
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}