#include <iostream>
#include <vector>
#include <cmath>
#define LOG_N 16
using namespace std;

vector<pair<int, int>> edge[40001];
int d[40001];
int d1[40001];
int visit[40001];
int p[40001][LOG_N];
int max_log_n = 0;

void dfs(int x, int depth, int distance, int parent)
{
	if (visit[x])
		return;
	visit[x] = true;
	d[x] = depth;
	d1[x] = distance;
	p[x][0] = parent;
	max_log_n = max(max_log_n, (int)floor(log2(d[x])) + 1);
	for (int i = 0; i < edge[x].size(); i++)
	{
		int nx = edge[x][i].first;
		int n_distance = edge[x][i].second;
		dfs(nx, depth + 1,distance + n_distance, x);
	}
}

void set_parent(int N)
{
	dfs(1, 0, 0, 0);
	for (int i = 1; i < max_log_n; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			p[j][i] = p[p[j][i - 1]][i - 1];
		}
	}
}

int lca(int x, int y)
{
	if(d[x] < d[y])
	{
		int temp = x;
		x = y;
		y = temp;
	}
	for(int i = max_log_n - 1; i >= 0; i--)
	{
		if(d[x] - d[y] >= 1 << i)
		{
			x = p[x][i];
		}
	}
	if (x == y)
		return x;
	for(int i = max_log_n - 1; i >= 0; i--)
	{
		if(p[x][i] != p[y][i])
		{
			x = p[x][i];
			y = p[y][i];
		}
	}
	return p[x][0];
}


int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b, distance;
		cin >> a >> b >> distance;
		edge[a].push_back({ b, distance});
		edge[b].push_back({a, distance});
	}
	set_parent(N);
	int M;
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << d1[x] + d1[y] - 2 * d1[lca(x, y)] << '\n';
	}
}