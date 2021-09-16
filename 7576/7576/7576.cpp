#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int M, N;
int box[1001][1001];
int box_count[1001][1001];
int visit[1001][1001];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
queue<pair<int, int>> q;

void bfs(int x, int y)
{
	int tx, ty, nx, ny;
	while (!q.empty())
	{
		tx = q.front().first;
		ty = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = tx + dx[i];
			ny = ty + dy[i];
			if (nx > 0 && ny > 0 && nx < M + 1 && ny < N + 1 && !visit[ny][nx] && box[ny][nx] == 0)
			{
				q.push(make_pair(nx, ny));
				visit[ny][nx] = true;
				box[ny][nx] = 1;
				box_count[ny][nx] = box_count[ty][tx] + 1;
			}
		}
	}
}

int main(void)
{
	int min_date = 0;
	cin >> M >> N;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			scanf("%d", &box[i][j]);
			if(!visit[i][j] && box[i][j] == 1)
			{
				q.push(make_pair(j, i));
				visit[i][j] = true;
			}
		}
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			if (box[i][j] == 1)
			{
				bfs(j, i);
			}
		}
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			if(box[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
			min_date = max(min_date, box_count[i][j]);
		}
	}
	cout << min_date << endl;
}