#include <iostream>
#include <queue>
using namespace std;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int experience[200];
int map[20][20];
int visit[20][20];
int N;
int shark_size = 2;
pair<int, int> shark_position;
int current_distance = 0;

bool bfs(pair<int, int> start)
{
	queue<pair<pair<int, int>, int>> q;
	int min_distance = 400;
	int min_x = 20;
	int min_y = 20;
	int start_x = start.first;
	int start_y = start.second;
	q.push(make_pair(make_pair(start_x, start_y), 0));
	map[start_y][start_x] = 0;
	visit[start_y][start_x] = true;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int distance = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (!visit[ny][nx])
			{
				if (map[ny][nx] > 0 && map[ny][nx] < shark_size)
				{
					if(distance + 1 < min_distance)
					{
						min_distance = distance + 1;
						min_x = nx;
						min_y = ny;
					}
					else if(distance + 1 == min_distance)
					{
						if(ny < min_y)
						{
							min_x = nx;
							min_y = ny;
						} else if(ny == min_y)
						{
							if(nx < min_x)
							{
								min_x = nx;
								min_y = ny;
							}
						}
					}
					q.push(make_pair(make_pair(nx, ny), distance + 1));
					visit[ny][nx] = true;
				}
				else if (map[ny][nx] == shark_size)
				{
					q.push(make_pair(make_pair(nx, ny), distance + 1));
					visit[ny][nx] = true;
				}
				else if(map[ny][nx] == 0)
				{
					q.push(make_pair(make_pair(nx, ny), distance + 1));
					visit[ny][nx] = true;
				}
			}
		}
	}
	if(min_distance != 400)
	{
		map[min_y][min_x] = 9;
		experience[shark_size]++;
		if (experience[shark_size] == shark_size)
			shark_size++;
		current_distance = min_distance;
		shark_position = make_pair(min_x, min_y);
		return true;
	}
	return false;
}

int main(void)
{
	int answer = 0;
	bool is_finish = false;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
				shark_position = make_pair(j, i);
		}
	}
	while (!is_finish)
	{
		current_distance = 0;
		for (int i = 0; i < 20; i++)
			fill_n(visit[i], 20, false);
		if (!bfs(shark_position))
			is_finish = true;
		else
			answer += current_distance;
	}
	cout << answer << '\n';
}