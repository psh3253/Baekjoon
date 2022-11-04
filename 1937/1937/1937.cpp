#include <iostream>
using namespace std;
int map[500][500];
int dp[500][500];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int dfs(int x, int y, int n)
{
	if (dp[y][x] != 0)
		return dp[y][x];
	dp[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
		if (map[y][x] < map[ny][nx])
		{
			dp[y][x] = max(dp[y][x], dfs(nx, ny, n) + 1);
		}
	}
	return dp[y][x];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dfs(j, i, n);
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			answer = max(answer, dp[i][j]);
		}
	}
	cout << answer << '\n';
}