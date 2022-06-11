#include <iostream>
#include <queue>
using namespace std;
bool is_finish = false;
int answer = 0;
int R, C;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
pair<int, int> swan;
char map[1500][1500];
bool visit[1500][1500];
queue<pair<int, int>> ice_q;
queue<pair<int, int>> buffer_ice_q;
queue<pair<int, int>> swan_q;
queue<pair<int, int>> buffer_swan_q;

void bfs_ice()
{
	while (!ice_q.empty())
	{
		int x = ice_q.front().first;
		int y = ice_q.front().second;
		ice_q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= C || ny >= R)
				continue;
			if (map[ny][nx] == 'X')
			{
				buffer_ice_q.push(make_pair(nx, ny));
				map[ny][nx] = '.';
			}
		}
	}
}

bool bfs_swan()
{
	while (!swan_q.empty())
	{
		int x = swan_q.front().first;
		int y = swan_q.front().second;
		swan_q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= C || ny >= R)
				continue;
			if (map[ny][nx] == 'L' && !visit[ny][nx])
			{
				is_finish = true;
				return true;
			}
			else if (map[ny][nx] == '.' && !visit[ny][nx])
			{
				swan_q.push(make_pair(nx, ny));
				visit[ny][nx] = true;
			}
			else if (map[ny][nx] == 'X' && !visit[ny][nx]) {
				buffer_swan_q.push(make_pair(nx, ny));
				visit[ny][nx] = true;
			}
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'L')
			{
				swan = make_pair(j, i);
			}
			if (map[i][j] == '.' || map[i][j] == 'L')
			{
				ice_q.push(make_pair(j, i));
			}
		}
	}
	swan_q.push(make_pair(swan.first, swan.second));
	visit[swan.second][swan.first] = true;
	while (true)
	{
		bfs_swan();
		if (is_finish)
			break;
		bfs_ice();
		answer++;
		swan_q = buffer_swan_q;
		while (!buffer_swan_q.empty())
			buffer_swan_q.pop();
		ice_q = buffer_ice_q;
		while (!buffer_ice_q.empty())
			buffer_ice_q.pop();

	}
	cout << answer << '\n';
}