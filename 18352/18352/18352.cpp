#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
vector<int> edge[300001];
int d[300001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[start] = 0;
	pq.push(make_pair(0,  start));
	while(!pq.empty())
	{
		int x = pq.top().second;
		int distance = pq.top().first;
		pq.pop();
		for (int i = 0; i < edge[x].size(); i++)
		{
			int nx = edge[x][i];
			int next_distance = distance + 1;
			if(next_distance < d[nx])
			{
				d[nx] = next_distance;
				pq.push(make_pair(next_distance, nx));
			}
		}
	}
}
int main(void)
{
	bool is_answer = false;
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	fill_n(d, 300000, INF);
	for(int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		edge[start].push_back(end);
	}
	dijkstra(X);
	for(int i = 1; i < N + 1; i++)
	{
		if (d[i] == K)
		{
			is_answer = true;
			cout << i << '\n';
		}
	}
	if (!is_answer)
		cout << -1 << '\n';
}