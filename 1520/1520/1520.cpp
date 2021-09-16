#include <iostream>
#include <utility>
using namespace std;
int M, N;
int map[501][501];
int visit[501][501];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int dfs(pair<int, int> cur)
{
	int x = cur.first;
	int y = cur.second;
	if (visit[y][x] != -1)
		return visit[y][x];
	if (y == M - 1 && x == N - 1)
		return 1;
	visit[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x > -1 && next_y > -1 && next_x < N && next_y < M && map[y][x] > map[next_y][next_x])
		{
			visit[y][x] += dfs(make_pair(next_x, next_y));
		}
	}
	return visit[y][x];
}


int main(void)
{
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			visit[i][j] = -1;
		}
	}
	int result = dfs(make_pair(0, 0));
	cout << result << '\n';
}