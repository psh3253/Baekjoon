#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int box[1000][1000] = { -1, };
bool visit[1000][1000] = { false, };
int day[1000][1000] = { 0, };
int dirX[4] = { 0, 1, 0, -1 };
int dirY[4] = { -1, 0, 1, 0 };
queue< pair<int, int>> q;

void bfs(int n, int m)
{
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dirY[i];
			int nx = x + dirX[i];
			if (!visit[ny][nx] && box[ny][nx] == 0 && nx > -1 && ny > -1 && nx < m && ny < n)
			{
				q.push(make_pair(ny, nx));
				visit[ny][nx] = true;
				day[ny][nx] = day[y][x] + 1;
			}
		}
	}
}

int main(void)
{
	int m, n, result = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &box[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] == 1)
			{
				q.push(make_pair(i, j));
				visit[i][j] = true;
			}
		}
	}
	bfs(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visit[i][j] == false && box[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
			if (day[i][j] > result)
			{
				result = day[i][j];
			}
		}
	}
	cout << result << endl;
	return 0;
}