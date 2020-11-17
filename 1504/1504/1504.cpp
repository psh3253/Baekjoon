#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> edge[801];
int cost[801];
int INF = 800001;
int n;

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 1; i < n + 1; i++)
	{
		cost[i] = INF;
	}
	cost[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int curcost = pq.top().first;
		int curpos = pq.top().second;
		pq.pop();

		if (cost[curpos] < curcost)
			continue;

		for (int i = 0; i < edge[curpos].size(); i++)
		{
			int nextpos = edge[curpos][i].first;
			int nextcost = curcost + edge[curpos][i].second;
			if (nextcost < cost[nextpos])
			{
				cost[nextpos] = nextcost;
				pq.push(make_pair(nextcost, nextpos));
			}
		}
	}
}

int main(void)
{
	int e;
	int a, b, c;
	int p1, p2;
	int case1, case2;
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back(make_pair(b, c));
		edge[b].push_back(make_pair(a, c));
	}
	cin >> p1 >> p2;
	dijkstra(1);
	case1 = cost[p1];
	case2 = cost[p2];

	dijkstra(p1);
	case1 += cost[p2];
	case2 += cost[p2];
	case2 += cost[n];

	dijkstra(p2);
	case1 += cost[n];
	if (min(case1, case2) >= INF)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << min(case1, case2) << endl;
	}
}