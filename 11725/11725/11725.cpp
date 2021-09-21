#include <iostream>
#include <vector>
using namespace std;
vector<int> edge[100001];
int visit[100001];

void dfs(int x, int prev)
{
	if (visit[x])
		return;
	visit[x] = prev;
	for(int i = 0; i < edge[x].size(); i++)
	{
		int nx = edge[x][i];
		if(!visit[nx])
		{
			dfs(nx, x);
		}
	}
}

int main(void)
{
	int N;
	cin >> N;
	for(int i = 0; i < N-1; i++)
	{
		int start, end;
		cin >> start >> end;
		edge[start].push_back(end);
		edge[end].push_back(start);
	}
	dfs(1, 0);
	for(int i = 2; i < N + 1; i++)
	{
		cout << visit[i] << '\n';
	}
}