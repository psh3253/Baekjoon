#include <iostream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

int dis[20001];
vector<pair<int, int>> a[20001];
int INF = 999999999;

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dis[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int curdis = pq.top().first;
		pq.pop();

		if (curdis > dis[cur])
			continue;
		
		for (int i = 0; i < a[cur].size(); i++)
		{
			int next = a[cur][i].second;
			int nextdis = a[cur][i].first + curdis;
			if (nextdis < dis[next])
			{
				dis[next] = nextdis;
				pq.push(make_pair(nextdis, next));
			}
		}
	}
}

int main(void)
{
	int v, e, start;
	int src, dst, weight;
	cin >> v >> e;
	cin >> start;
	for (int i = 1; i < v + 1; i++)
	{
		dis[i] = INF;
	}
	
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &src, &dst, &weight);
		a[src].push_back(make_pair(weight, dst));
	}
	dijkstra(start);
	for (int i = 1; i < v + 1; i++)
	{
		if (dis[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dis[i]);
	}
	return 0;
}
