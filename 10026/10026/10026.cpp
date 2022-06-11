#include <iostream>
#include <queue>
using namespace std;
int N;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
char image[100][100];
bool visit[100][100][2];

void bfs(pair<int, int> start, int is_color_medicine)
{
	queue<pair<int, int>> q;
	int start_x = start.first;
	int start_y = start.second;
	q.push(make_pair(start_x, start_y));
	visit[start_y][start_x][is_color_medicine] = true;
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
			if(is_color_medicine == 0)
			{
				if(!visit[ny][nx][is_color_medicine] && image[ny][nx] == image[y][x])
				{
					q.push(make_pair(nx, ny));
					visit[ny][nx][is_color_medicine] = true;
				}
			}
			else
			{
				if (visit[ny][nx][is_color_medicine])
					continue;
				if(image[ny][nx] == image[y][x] || (image[ny][nx] == 'R' && image[y][x] == 'G') || (image[ny][nx] == 'G' && image[y][x] == 'R'))
				{
					q.push(make_pair(nx, ny));
					visit[ny][nx][is_color_medicine] = true;
				}
			}
		}
	}
}

int main(void)
{
	int answer1 = 0, answer2 = 0;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> image[i][j];
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(!visit[i][j][0])
			{
				bfs(make_pair(j, i), 0);
				answer1++;
			}
			if (!visit[i][j][1])
			{
				bfs(make_pair(j, i), 1);
				answer2++;
			}
		}
	}
	cout << answer1 << " " << answer2 << '\n';
}