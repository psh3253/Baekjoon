#include <iostream>
#include <queue>
using namespace std;
int answer;
int N, M;
int map[8][8];
int temp_map[8][8];
bool visit[8][8];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs(vector<pair<int, int>> start)
{
	queue<pair<int, int>> q;
	for (int i = 0; i < start.size(); i++)
	{
		visit[start[i].second][start[i].first] = true;
		q.push(make_pair(start[i].first, start[i].second));
	}
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (temp_map[ny][nx] == 0 && !visit[ny][nx])
			{
				q.push(make_pair(nx, ny));
				temp_map[ny][nx] = 2;
				visit[ny][nx] = true;
			}
		}
	}
}

void backtracking(int count)
{
	if (count == 3)
	{
		int temp = 0;
		vector<pair<int, int>> v;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 2)
					v.push_back(make_pair(j, i));
				temp_map[i][j] = map[i][j];
				visit[i][j] = false;
			}
		}
		bfs(v);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (temp_map[i][j] == 0)
					temp++;
			}
		}
		answer = max(answer, temp);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				backtracking(count + 1);
				map[i][j] = 0;
			}
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	backtracking(0);
	cout << answer << '\n';
}