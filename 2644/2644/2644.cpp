#include <iostream>
#include <vector>
using namespace std;
vector<int> edge[101];
int visit[101];

void dfs(int x, int parent)
{
	if (visit[x] > 0 )
		return;
	visit[x] = visit[parent] + 1;
	for(int i = 0; i < edge[x].size(); i++)
	{
		int nx = edge[x][i];
		dfs(nx, x);
	}
}

int main(void)
{
	int n;
	int start, end;
	int m;
	cin >> n;
	cin >> start >> end;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int parent, child;
		cin >> parent >> child;
		edge[parent].push_back(child);
		edge[child].push_back(parent);
	}
	dfs(start, 0);
	if (visit[end])
		cout << visit[end] - 1 << '\n';
	else
		cout << -1 << '\n';
}