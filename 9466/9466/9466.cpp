#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int edge[100001];
bool visit[100001];
int answer;
queue<int> q;

void dfs(int x)
{
	if (visit[x])
	{
		while(!q.empty() && q.front() != x)
		{
			q.pop();
		}
		answer -= q.size();
		return;
	}
	visit[x] = true;
	q.push(x);
	int nx = edge[x];
	dfs(nx);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		memset(visit, false, sizeof(visit[0]) * 100001);
		int n;
		cin >> n;
		answer = n;
		for(int j = 1; j < n + 1; j++)
		{
			cin >> edge[j];
		}
		for(int j = 1; j < n + 1; j++)
		{
			if (!visit[j])
				dfs(j);
			q = {};
		}
		cout << answer << '\n';
	}
}