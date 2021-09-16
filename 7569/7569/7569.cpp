#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int M, N, H;
int box[101][101][101];
int visit[101][101][101];
int dx[8] = { 0, 0, 1, 0, -1, 0 };
int dy[8] = { 0, -1, 0, 1, 0, 0 };
int dz[8] = { 1, 0, 0, 0, 0, -1 };
queue<pair<pair<int, int>, int>> q;

void bfs()
{
	int x, y, z, nx, ny, nz;
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		z = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			nz = z + dz[i];
			if (nx > 0 && ny > 0 && nz > 0 && nx < M + 1 && ny < N + 1 && nz < H + 1 && !visit[nz][ny][nx] && box[nz][ny][nx] == 0)
			{
				q.push(make_pair(make_pair(nx, ny), nz));
				visit[nz][ny][nx] = true;
				box[nz][ny][nx] = box[z][y][x] + 1;
			}
		}
	}
}

int main(void)
{
	int min_date = 0;
	cin >> M >> N >> H;
	for (int i = 1; i < H + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			for (int k = 1; k < M + 1; k++)
			{
				scanf("%d", &box[i][j][k]);
				if (box[i][j][k] == 1)
					q.push(make_pair(make_pair(k, j), i));
			}
		}
	}
	bfs();
	for (int i = 1; i < H + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			for (int k = 1; k < M + 1; k++)
			{
				if (box[i][j][k] == 0) {
					cout << -1 << endl;
					return 0;
				}
				min_date = max(min_date, box[i][j][k]);
			}
		}
	}
	cout << min_date - 1 << endl;
}