#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int start_pos, end_pos;
int N, M;
vector<pair<int, int>> edge[100000];
int max_weight[10001];
bool visit[10001];

void backtracking(int x)
{
	if(x == end_pos)
	{
		return;
	}
	for(int i = 0; i < edge[x].size(); i++)
	{
		int nx = edge[x][i].first;
		int cost = edge[x][i].second;
		if(!visit[nx])
		{
			if (max_weight[x] == 0)
				max_weight[nx] = max(cost, max_weight[nx]);
			else
				max_weight[nx] = max(min(max_weight[x], cost), max_weight[nx]);
			visit[nx] = true;
			backtracking(nx);
			visit[nx] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		edge[A].push_back(make_pair(B, C));
		edge[B].push_back(make_pair(A, C));
	}
	cin >> start_pos >> end_pos;
	visit[start_pos] = true;
	backtracking(start_pos);
	cout << max_weight[end_pos] << '\n';
}