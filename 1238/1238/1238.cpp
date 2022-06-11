#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
vector<pair<int, int>> edge[1001];
int d[1001];
int home_to_X[1001];
int X_to_home[1001];

void dijkstra(int start)
{
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	d[start] = 0;
	while(!pq.empty())
	{
		int current = pq.top().second;
		int current_distance = pq.top().first;
		pq.pop();
		if (current_distance > d[current])
			continue;
		for(int i = 0; i < edge[current].size(); i++)
		{
			int next = edge[current][i].first;
			int next_distance = edge[current][i].second + current_distance;
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
	int answer = 0;
	int N, M, X;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
	{
		int start, end, distance;
		cin >> start >> end >> distance;
		edge[start].push_back(make_pair(end, distance));
	}
	for(int i = 1; i < N + 1; i++)
	{
		d[i] = INF;
	}
	dijkstra(X);
	for (int i = 1; i < N + 1; i++)
	{
		X_to_home[i] = d[i];
		d[i] = INF;
	}
	for(int i = 1; i < N + 1; i++)
	{
		dijkstra(i);
		answer = max(answer, X_to_home[i] + d[X]);
		for (int j = 1; j < N + 1; j++)
		{
			d[j] = INF;
		}
	}
	cout << answer << '\n';
}