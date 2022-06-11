#include <iostream>
#include <cstring>
#include <vector>
#define LOG_N 15
using namespace std;
int N;
vector<int> edge[10001];
int parent[10001][LOG_N];
int d[10001];
bool visit[10001];

void dfs(int x, int depth, int p)
{
	if (visit[x])
		return;
	visit[x] = true;
	d[x] = depth;
	parent[x][0] = p;
	for(int i = 0;i < edge[x].size(); i++)
	{
		int nx = edge[x][i];
		if (p != nx)
		{
			dfs(nx, depth + 1, x);
		}
	}
}

void set_parent(int root)
{
	dfs(root, 0, 0);
	for(int i = 1; i < LOG_N; i++)
	{
		for(int j = 1; j < N + 1; j++)
		{
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
}

int lca(int x, int y)
{
	if (d[x] < d[y])
		swap(x, y);
	for(int i = LOG_N - 1; i >= 0; i--)
	{
		if(d[x] - d[y] >= (1 << i))
		{
			x = parent[x][i];
		}
	}
	if (x == y)
		return x;
	for(int i = LOG_N - 1; i >=0; i--)
	{
		if(parent[x][i] != parent[y][i])
		{
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	return parent[x][0];
}

int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int root = 0;
		for (int j = 0; j < 10001; j++)
			edge[j].clear();
		memset(visit, false, sizeof(visit));
		memset(d, 0, sizeof(d));
		memset(parent, 0, sizeof(parent));
		cin >> N;
		for (int j = 0; j < N - 1; j++)
		{
			int x, y;
			cin >> x >> y;
			edge[x].push_back(y);
			visit[y] = true;
		}
		for(int j = 1; j < N + 1; j++)
		{
			if(!visit[j])
			{
				root = j;
				break;
			}
		}
		memset(visit, false, sizeof(visit));
		set_parent(root);
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
}