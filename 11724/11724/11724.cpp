#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> edge[1001];
bool visit[1001] = { false };

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty())
	{
		int pos = q.front();
		q.pop();
		for (int i = 0; i < edge[pos].size(); i++)
		{
			int npos = edge[pos][i];
			if (!visit[npos])
			{
				q.push(npos);
				visit[npos] = true;
			}
		}
	}
}

int main(void)
{
	int N, M, u, v;
	int con = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (!visit[i])
		{
			bfs(i);
			con++;
		}
	}
	cout << con << endl;
	return 0;
}