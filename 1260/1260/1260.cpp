#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> edge[1001];
vector<bool> dfsVisit(1001, false);
vector<bool> bfsVisit(1001, false);

void dfs(int x)
{
	if (dfsVisit[x])
		return;
	dfsVisit[x] = true;
	cout << x << " ";
	for (int i = 0; i < edge[x].size(); i++)
	{
		int y = edge[x][i];
		dfs(y);
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	bfsVisit[start] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 0; i < edge[x].size(); i++)
		{
			int y = edge[x][i];
			if(!bfsVisit[y])
			{
				q.push(y);
				bfsVisit[y] = true;
			}
		}
	}
}

int main(void)
{
	int n, m, v, src, dst;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		cin >> src >> dst;
		edge[src].push_back(dst);
		edge[dst].push_back(src);
	}
	for(int i=0; i<1001; i++)
	{
		sort(edge[i].begin(), edge[i].end());
	}
	dfs(v);
	printf("\n");
	bfs(v);
	return 0;
}