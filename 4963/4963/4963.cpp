#include <iostream>
#include <queue>
using namespace std;
int dx[8] = { 0, 1, 0, -1, -1, 1, -1, 1};
int dy[8] = { -1, 0, 1, 0, 1, -1, -1, 1 };
int w, h;
int map[50][50];
bool visit[50][50];

void bfs(pair<int, int> start)
{
	queue<pair<int, int>> q;
	q.push(make_pair(start.first, start.second));
	visit[start.second][start.first] = true;
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= w || ny >= h)
				continue;
			if(!visit[ny][nx] && map[ny][nx] == 1)
			{
				q.push(make_pair(nx, ny));
				visit[ny][nx] = true;
			}
		}
	}
}

int main(void)
{
	while (true)
	{
		int answer = 0;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
				visit[i][j] = false;
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (!visit[i][j] && map[i][j] == 1)
				{
					bfs(make_pair(j, i));
					answer++;
				}
			}
		}
		cout << answer << '\n';
	}
}