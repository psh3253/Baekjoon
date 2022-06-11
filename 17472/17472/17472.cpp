#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int answer = 0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int island_number = 1;
int N, M;
int map[10][10];
vector<pair<int, int>> island_location[7];
vector<pair<int, pair<int, int>>> edge;
int set[7];

int get_parent(int x)
{
	if (set[x] == x)
		return x;
	return set[x] = get_parent(set[x]);
}

void union_parent(int x, int y)
{
	int parent_x = get_parent(x);
	int parent_y = get_parent(y);
	if(parent_x < parent_y)
	{
		set[parent_y] = parent_x;
	}
	else
	{
		set[parent_x] = parent_y;
	}
}

void kruskal()
{
	for(int i = 0; i < edge.size(); i++)
	{
		int x = edge[i].second.first;
		int y = edge[i].second.second;
		int distance = edge[i].first;
		if(get_parent(x) != get_parent(y))
		{
			union_parent(x, y);
			answer += distance;
		}
	}
}

void find_brigde(pair<int, int> location)
{
	int x = location.first;
	int y = location.second;
	for (int i = 0; i < 4; i++)
	{
		int distance = 0;
		int nx = x;
		int ny = y;
		while (true)
		{
			nx += dx[i];
			ny += dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N || map[ny][nx] == map[y][x])
				break;
			if (map[ny][nx] == 0)
				distance++;
			else
			{
				if (distance > 1)
					edge.push_back(make_pair(distance, make_pair(map[y][x], map[ny][nx])));
				break;
			}
		}
	}
}

void dfs(pair<int, int> location)
{
	int x = location.first;
	int y = location.second;
	if (map[y][x] != -1)
		return;
	map[y][x] = island_number;
	island_location[island_number].push_back(make_pair(x, y));
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;
		dfs(make_pair(nx, ny));
	}
}

int main(void)
{
	bool is_all_connected = true;
	for(int i = 1; i < 7; i++)
	{
		set[i] = i;
	}
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				map[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == -1)
			{
				dfs(make_pair(j, i));
				island_number++;
			}
		}
	}

	for (int i = 1; i < 7; i++)
	{
		for (int j = 0; j < island_location[i].size(); j++)
		{
			find_brigde(island_location[i][j]);
		}
	}

	sort(edge.begin(), edge.end());
	kruskal();

	for(int i = 2; i < island_number; i++)
	{
		if (get_parent(i) != 1)
			is_all_connected = false;
	}

	if (is_all_connected)
		cout << answer << '\n';
	else
		cout << -1 << '\n';
}