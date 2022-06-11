#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<pair<int, int>> edge[10001];
bool visit[10001];
int max_index = 0;
int max_cost = 0;

void dfs(int x, int cost)
{
	if (visit[x])
		return;
	visit[x] = true;
	if(cost > max_cost)
	{
		max_cost = cost;
		max_index = x;
	}
	for(int i = 0; i < edge[x].size(); i++)
	{
		int nx = edge[x][i].first;
		int next_cost = edge[x][i].second + cost;
		dfs(nx, next_cost);
	}
}

int main(void)
{
	int n;
	cin >> n;
	memset(visit, false, sizeof(visit));
	for(int i = 0; i < n - 1; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		edge[start].push_back({ end, cost });
		edge[end].push_back({ start, cost });
	}
	dfs(1, 0);
	int temp = max_index;
	max_index = 0;
	max_cost = 0;
	memset(visit, false, sizeof(visit));
	dfs(temp, 0);
	cout << max_cost << '\n';
}