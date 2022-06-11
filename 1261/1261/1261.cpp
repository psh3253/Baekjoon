#include <iostream>
#include <deque>
#define INF 987654321
using namespace std;
int M, N;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int map[100][100];
int d[100][100];

void zero_one_bfs()
{
	deque<pair<int, int>> dq;
	int answer = 0;
	dq.push_back(make_pair(0, 0));
	d[0][0] = 0;
	while(!dq.empty())
	{
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if(map[ny][nx] == 1)
			{
				if(d[y][x] + 1 < d[ny][nx])
				{
					d[ny][nx] = d[y][x] + 1;
					dq.push_back(make_pair(nx, ny));
				}
			}
			else
			{
				if(d[y][x] < d[ny][nx])
				{
					d[ny][nx] = d[y][x];
					dq.push_front(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(void)
{
	cin >> M >> N;
	for(int i = 0; i < N; i++)
	{
		fill_n(d[i], M, INF);
		for(int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	zero_one_bfs();
	cout << d[N - 1][M - 1] << '\n';
}