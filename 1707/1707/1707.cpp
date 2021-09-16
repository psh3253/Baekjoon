#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int K, V, E;
int visit[20001];
vector<int> edge[20001];

int bfs(int start)
{
	int x, nx;
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		for (int i = 0; i < edge[x].size(); i++)
		{
			nx = edge[x][i];
			if (!visit[nx])
			{
				q.push(nx);
				if (visit[x] == 1)
				{
					visit[nx] = 2;
				}
				else
				{
					visit[nx] = 1;
				}
			}
		}
	}
	return 1;
}

bool isBipartiteGraph()
{
	for (int i = 1; i < V; i++)
	{
		for (int j = 0; j < edge[i].size(); j++)
		{
			if (visit[edge[i][j]] == visit[i])
				return 0;
		}
	}
	return 1;
}

int main(void)
{
	int x, y, result;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		result = 0;
		fill(visit, visit + 20000, 0);
		for (int j = 0; j < 20001; j++) {
			edge[j].clear();
		}
		cin >> V >> E;
		for (int j = 0; j < E; j++)
		{
			cin >> x >> y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		for (int j = 1; j < V + 1; j++)
		{
			if (!visit[j]) {
				bfs(j);
			}
		}
		if (isBipartiteGraph())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}