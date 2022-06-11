#include <iostream>
#include <vector>
#define LOG_N 16
using namespace std;
vector<int> edge[50001];
bool visit[50001];
int depth[50001];
int parent[50001][LOG_N];

void dfs(int x, int d, int p)
{
	if (visit[x])
		return;
	visit[x] = true;
	depth[x] = d;
	parent[x][0] = p;
	for(int i = 0; i < edge[x].size(); i++)
	{
		int nx = edge[x][i];
		dfs(nx, d + 1, x);
	}
}

void set_parent(int N)
{
	dfs(1, 0, 0);
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
	if(depth[x] < depth[y])
	{
		int temp = x;
		x = y;
		y = temp;
	}

	for(int i = LOG_N - 1; i >= 0; i--)
	{
		if(depth[x] - depth[y] >= (1 << i))
		{
			x = parent[x][i];
		}
	}
	if (x == y)
		return x;
	for(int i = LOG_N - 1; i >= 0; i--)
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
	int N;
	cin >> N;
	for(int i = 0; i < N - 1; i++)
	{
		int A, B;
		cin >> A >> B;
		edge[A].push_back(B);
		edge[B].push_back(A);
	}
	set_parent(N);
	int M;
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		int X, Y;
		cin >> X >> Y;
		cout << lca(X, Y) << '\n';
	}
}