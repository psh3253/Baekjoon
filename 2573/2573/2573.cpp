#include <iostream>
#include <queue>
using namespace std;
int N, M;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int map[300][300];
int decrease[300][300];
int visit[300][300];
queue<pair<int, int>> melt_q;
queue<pair<int, int>> melt_buffer_q;

void bfs_ice(pair<int, int> start)
{
	queue<pair<int, int>> ice_q;
	int start_x = start.first;
	int start_y = start.second;
	ice_q.push(make_pair(start_x, start_y));
	visit[start_y][start_x] = true;
	while (!ice_q.empty())
	{
		int x = ice_q.front().first;
		int y = ice_q.front().second;
		ice_q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx >= M - 1 || ny >= N - 1)
				continue;
			if (!visit[ny][nx] && map[ny][nx] > 0)
			{
				ice_q.push(make_pair(nx, ny));
				visit[ny][nx] = true;
			}
		}
	}
}

void bfs_melt()
{
	for (int i = 0; i < N; i++)
		fill_n(decrease[i], M, 0);
	while (!melt_q.empty())
	{
		int x = melt_q.front().first;
		int y = melt_q.front().second;
		melt_q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (map[ny][nx] == 0)
			{
				decrease[y][x]++;
			}
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			map[i][j] -= decrease[i][j];
			if (map[i][j] <= 0)
				map[i][j] = 0;
			else
				melt_buffer_q.push(make_pair(j, i));
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool is_all_melt = false;
	bool is_finish = false;
	int answer = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] > 0)
				melt_q.push(make_pair(j, i));
		}
	}
	while (true)
	{
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			fill_n(visit[i], M, false);
		}
		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < M - 1; j++)
			{
				if (!visit[i][j] && map[i][j] > 0)
				{
					count++;
					if (count == 2)
					{
						is_finish = true;
						break;
					}
					bfs_ice(make_pair(j, i));
				}
			}
			if (is_finish)
				break;
		}
		if (count == 0)
		{
			is_finish = true;
			is_all_melt = true;
		}
		if (is_finish)
			break;
		bfs_melt();
		melt_q = melt_buffer_q;
		while (!melt_buffer_q.empty())
			melt_buffer_q.pop();
		answer++;
	}
	if (is_all_melt)
		cout << 0 << '\n';
	else
		cout << answer << '\n';
}