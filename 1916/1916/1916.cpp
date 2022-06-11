#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int d[1001];
vector<pair<int, int>> edge[1001];

void dijkstra(int start)
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[start] = 0;
	pq.push(make_pair(0, start));
	while(!pq.empty())
	{
		int current = pq.top().second;
		int distance = pq.top().first;
		pq.pop();
		if (distance > d[current])
			continue;
		for(int i = 0; i < edge[current].size(); i++)
		{
			int next = edge[current][i].first;
			int next_distance = edge[current][i].second + distance;
			if(next_distance < d[next])
			{
				d[next] = next_distance;
				pq.push(make_pair(next_distance, next));
			}
		}
	}
}

int main(void)
{
	int N, M;
	int start, end, cost;
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end >> cost;
		edge[start].push_back(make_pair(end, cost));
	}
	for (int i = 1; i < N + 1; i++)
	{
		d[i] = INF;
	}
	cin >> start >> end;
	dijkstra(start);
	cout << d[end] << '\n';
}