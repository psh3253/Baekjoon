#include <iostream>
#include <vector>
#include <cmath>
#define LOG_N 17
using namespace std;
vector<int> edge[100001];
int d[100001];
bool visit[100001];
int p[100001][LOG_N];
int max_log_n = 0;

void dfs(int x, int depth, int parent)
{
	if (visit[x])
		return;
	visit[x] = true;
	p[x][0] = parent;
	d[x] = depth;
	max_log_n = max(max_log_n, (int)floor(log2(depth)) + 1);
	for(int i = 0; i < edge[x].size(); i++)
	{
		int nx = edge[x][i];
		dfs(nx, depth + 1, x);
	}
}

void set_parent(int N)
{
	dfs(1, 0, 0);
	for(int i = 1; i < max_log_n; i++)
	{
		for(int j = 1; j < N + 1; j++)
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for(int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	set_parent(N);
	int M;
	cin >> M;
	for(int i = 0 ; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << lca(x, y) << "\n";
	}
}