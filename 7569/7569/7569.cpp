#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int box[100][100][100];
bool visit[100][100][100];
int day[100][100][100];
int dirX[6] = { 0, 1, 0, -1, 0, 0 };
int dirY[6] = { -1, 0, 1, 0, 0, 0 };
int dirZ[6] = { 0, 0 ,0 , 0, 1, -1 };
queue<pair<pair<int, int>, int>> q;

void bfs(int m, int n, int h)
{
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dirX[i];
			int ny = y + dirY[i];
			int nz = z + dirZ[i];
			if (nx > -1 && ny > -1 && nz > -1 && nx < m && ny < n && nz < h && box[nz][ny][nx] == 0 && !visit[nz][ny][nx])
			{
				q.push(make_pair(make_pair(nx, ny), nz));
				visit[nz][ny][nx] = true;
				day[nz][ny][nx] = day[z][y][x] + 1;
			}
		}
	}
}

int main(void)
{
	int m, n, h;
	long long result = 0;;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				
				scanf("%d", &box[i][j][k]);
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (box[i][j][k] == 1)
				{
					q.push(make_pair(make_pair(k, j), i));
					visit[i][j][k] = true;
				}
			}
		}
	}
	bfs(m, n, h);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (box[i][j][k] == 0 && !visit[i][j][k])
				{
					printf("-1\n");
					return 0;
				}
				else
				{
					if (day[i][j][k] > result)
						result = day[i][j][k];
				}
			}
		}
	}
	printf("%lld\n", result);
	return 0;
}