#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int N, M;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int map[1001][1001];
int visit[1001][1001][2];

int bfs()
{
	int x, y, break_wall, nx, ny;
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 1), 0));
	visit[1][1][0] = 1;
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		break_wall = q.front().second;
		if (x == M && y == N)
			return visit[N][M][break_wall];
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx > 0 && ny > 0 && nx < M + 1 && ny < N + 1 && !visit[ny][nx][break_wall])
			{
				if (map[ny][nx] == 0)
				{
					q.push(make_pair(make_pair(nx, ny), break_wall));
					visit[ny][nx][break_wall] = visit[y][x][break_wall] + 1;
				}
				else if (map[ny][nx] == 1 && !break_wall)
				{
					q.push(make_pair(make_pair(nx, ny), 1));
					visit[ny][nx][1] = visit[y][x][0] + 1;
				}
			}
		}
	}
	return -1;
}

int main(void)
{
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	cout << bfs() << endl;
}