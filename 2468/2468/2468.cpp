#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int N;
int map[100][100];
bool visit[100][100];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs(pair<int, int> start, int water_height)
{
	queue<pair<int, int>> q;
	q.push(make_pair(start.first, start.second));
	visit[start.second][start.first] = true;
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if(!visit[ny][nx] && map[ny][nx] > water_height)
			{
				q.push(make_pair(nx, ny));
				visit[ny][nx] = true;
			}
		}
	}
}

int main(void)
{
	int answer = 0;
	int max_height = 0;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			max_height = max(max_height, map[i][j]);
		}
	}
	for(int i = 0; i < max_height; i++)
	{
		int temp = 0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				visit[j][k] = false;
			}
		}
		for(int j = 0; j < N; j++)
		{
			for(int k = 0; k < N; k++)
			{
				if(!visit[j][k] && map[j][k] > i)
				{
					bfs(make_pair(k, j), i);
					temp++;
				}
			}
		}
		answer = max(answer, temp);
	}
	cout << answer << '\n';
}