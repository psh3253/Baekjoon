#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define INF 200000000
using namespace std;
int min_distance[801];
vector<pair<int, int>> edge[801];

void dijkstra(int start)
{
	int current, current_distance, next, next_distance;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	min_distance[start] = 0;
	while (!pq.empty())
	{
		current = pq.top().second;
		current_distance = pq.top().first;
		pq.pop();
		if (current_distance > min_distance[current])
			continue;
		for (int i = 0; i < edge[current].size(); i++)
		{
			next = edge[current][i].first;
			next_distance = edge[current][i].second + current_distance;
			if (next_distance < min_distance[next])
			{
				pq.push(make_pair(next_distance, next));
				min_distance[next] = next_distance;
			}
		}
	}
}

int main(void)
{
	int result;
	int N, E;
	int a, b, c;
	int v1, v2;
	int start_v1, start_v2, v1_v2, end_v1, end_v2;
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		edge[a].push_back(make_pair(b, c));
		edge[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;
	fill(min_distance, min_distance + N + 1, INF);
	dijkstra(1);
	start_v1 = min_distance[v1];
	start_v2 = min_distance[v2];
	fill(min_distance, min_distance + N + 1, INF);
	dijkstra(v1);
	v1_v2 = min_distance[v2];
	fill(min_distance, min_distance + N + 1, INF);
	dijkstra(N);
	end_v1 = min_distance[v1];
	end_v2 = min_distance[v2];
	result = min(start_v1 + v1_v2 + end_v2, start_v2 + v1_v2 + end_v1);
	if (result >= INF)
		cout << -1 << '\n';
	else
		cout << result << '\n';
}