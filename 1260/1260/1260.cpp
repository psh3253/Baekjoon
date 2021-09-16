#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool visit[1001] = { false, };
vector<int> edge[1001];

void dfs(int x)
{
	int y;
	if (visit[x])
		return;
	visit[x] = true;
	cout << x << ' ';
	for (int i = 0; i < edge[x].size(); i++)
	{
		y = edge[x][i];
		dfs(y);
	}
}

void bfs(int start)
{
	int x, y;
	queue<int> queue;
	queue.push(start);
	visit[start] = true;
	while (!queue.empty())
	{
		x = queue.front();
		cout << x << " ";
		queue.pop();
		for (int i = 0; i < edge[x].size(); i++)
		{
			y = edge[x][i];
			if (!visit[y])
			{
				queue.push(y);
				visit[y] = true;
			}
		}
	}
}

int main(void)
{
	int N, M, V, x, y;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for (int i = 0; i < N + 1; i++)
	{
		sort(edge[i].begin(), edge[i].end());
	}
	dfs(V);
	cout << endl;
	fill_n(visit, 1001, false);
	bfs(V);
	cout << endl;
}