#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int M, N;
int field[50][50];
bool visit[50][50];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs(int x, int y)
{
	int tx, ty, nx, ny;
	queue<pair<int, int>> queue;
	queue.push(make_pair(x, y));
	visit[y][x] = true;
	while (!queue.empty())
	{
		tx = queue.front().first;
		ty = queue.front().second;
		queue.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = tx + dx[i];
			ny = ty + dy[i];
			if (nx > -1 && ny > -1 && nx < M && ny < N && !visit[ny][nx] && field[ny][nx] == 1)
			{
				queue.push(make_pair(nx, ny));
				visit[ny][nx] = true;
			}
		}
	}
}

int main(void)
{
	int T, K, X, Y, earthworm_count;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;
		fill(field[0], field[49], 0);
		fill(visit[0], visit[49], false);
		earthworm_count = 0;
		for (int j = 0; j < K; j++)
		{
			cin >> X >> Y;
			field[Y][X] = 1;
		}
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (field[j][k] == 1 && !visit[j][k])
				{
					earthworm_count++;
					bfs(k, j);
				}
			}
		}
		cout << earthworm_count << endl;
	}
}