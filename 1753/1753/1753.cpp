#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define INF 300000
using namespace std;
vector<pair<int, int>> edge[20001];
int min_distance[20001];

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
	int V, E, K, source, destination, weight;
	cin >> V >> E;
	cin >> K;
	for (int i = 1; i < V + 1; i++)
	{
		min_distance[i] = INF;
	}
	for (int i = 0; i < E; i++)
	{
		cin >> source >> destination >> weight;
		edge[source].push_back(make_pair(destination, weight));
	}
	dijkstra(K);
	for (int i = 1; i < V + 1; i++)
	{
		if (min_distance[i] == INF)
			cout << "INF" << '\n';
		else
			cout << min_distance[i] << '\n';
	}
}