#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int M, N;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int paper[100][100];
int visit[100][100];

int bfs(pair<int, int> start)
{
	int area = 0;
	queue<pair<int, int>> q;
	int start_x = start.first;
	int start_y = start.second;
	q.push(make_pair(start_x, start_y));
	visit[start_y][start_x] = true;
	area++;
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if(!visit[ny][nx] && paper[ny][nx] == 0)
			{
				q.push(make_pair(nx, ny));
				visit[ny][nx] = true;
				area++;
			}
		}
	}
	return area;
}

int main(void)
{
	int K;
	int area_count = 0;
	vector<int> area;
	cin >> M >> N >> K;
	for(int i = 0; i < K; i++)
	{
		int start_x, start_y, destination_x, destination_y;
		cin >> start_x >> start_y >> destination_x >> destination_y;
		for(int j = start_x; j < destination_x; j++)
		{
			for (int k = start_y; k < destination_y; k++)
				paper[k][j] = 1;
		}
	}
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(!visit[i][j] && paper[i][j] == 0)
			{
				area.push_back(bfs(make_pair(j, i)));
				area_count++;
				
			}
		}
	}
	sort(area.begin(), area.end());
	cout << area_count << "\n";
	for(int i = 0; i < area.size(); i++)
	{
		cout << area[i] << " ";
	}
	cout << "\n";
}