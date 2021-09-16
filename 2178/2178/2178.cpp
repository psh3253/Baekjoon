#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int N, M;
int maze[101][101];
int maze_distance[101][101];
bool visit[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs()
{
	int x, y, nx, ny;
	queue<pair<int, int>> queue;
	queue.push(make_pair(1, 1));
	visit[1][1] = true;
	maze_distance[1][1] = 1;
	while (!queue.empty())
	{
		x = queue.front().first;
		y = queue.front().second;
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx > 0 && ny > 0 && nx < M + 1 && ny < N + 1 && !visit[ny][nx] && maze[ny][nx] == 1)
			{
				queue.push(make_pair(nx, ny));
				visit[ny][nx] = true;
				maze_distance[ny][nx] = maze_distance[y][x] + 1;
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}
	bfs();
	cout << maze_distance[N][M] << endl;
}