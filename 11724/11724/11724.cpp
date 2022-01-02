#include <iostream>
#include <queue>
using namespace std;
vector<int> edge[1001];
bool visit[1001];

void bfs(int start)
{
	queue<int> q;
	visit[start] = true;
	q.push(start);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(int i = 0; i < edge[x].size(); i++)
		{
			int nx = edge[x][i];
			if(!visit[nx])
			{
				q.push(nx);
				visit[nx] = true;
			}
		}
	}
}

int main(void)
{
	int answer = 0;
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i = 1; i < N + 1; i++)
	{
		if (!visit[i])
		{
			bfs(i);
			answer++;
		}
	}
	cout << answer << '\n';
}