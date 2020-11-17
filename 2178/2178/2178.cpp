#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int maze[101][101];
bool visit[101][101] = { false, };
int c[101][101] = { 0, };
int dirX[4] = { 0, 1, 0, -1 };
int dirY[4] = { -1, 0, 1, 0 };

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	visit[1][1] = true;
	c[1][1] = 1;
	while (!q.empty())
	{
		pair<int, int> x = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = x.first + dirY[i];
			int nx = x.second + dirX[i];
			if (maze[ny][nx] == 1 && !visit[ny][nx])
			{
				q.push(make_pair(ny, nx));
				visit[ny][nx] = true;
				c[ny][nx] = c[x.first][x.second] + 1;
				if (nx == m && ny == n)
				{
					cout << c[ny][nx] << endl;
					return 0;
				}
			}
		}
	}
}