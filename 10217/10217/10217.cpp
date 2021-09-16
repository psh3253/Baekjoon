#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define INF 200000
using namespace std;
int N, M, K;
vector<pair<pair<int, int>, int>> edge[101];
int min_distance[101][10001];


void dijkstra(int start)
{
	int current, current_distance, current_cost, next, next_distance, next_cost;
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
	pq.push(make_pair(make_pair(0, 0), start));
	min_distance[start][0] = 0;
	while(!pq.empty())
	{
		current_distance = pq.top().first.first;
		current_cost = pq.top().first.second;
		current = pq.top().second;
		pq.pop();
		if (current_distance > min_distance[current][current_cost])
			continue;
		for(int i = 0; i < edge[current].size(); i++)
		{
			next = edge[current][i].first.first;
			next_distance = edge[current][i].second + current_distance;
			next_cost = edge[current][i].first.second + current_cost;
			if (next_cost > M)
				continue;
			if(next_distance < min_distance[next][next_cost] )
			{
				pq.push(make_pair(make_pair(next_distance, next_cost), next));
				min_distance[next][next_cost] = next_distance;
			}
		}
	}
}

int main(void)
{
	int result;
	int T;
	int u, v, c, d;
	cin >> T;
	for(int i = 0; i< T; i++)
	{
		cin >> N >> M >> K;
		for(int j = 0; j < N + 1; j++)
		{
			edge[j].clear();
			fill(min_distance[j], min_distance[j] + 10001, INF);
		}
		result = INF;
		for (int j = 0; j < K; j++)
		{
			cin >> u >> v >> c >> d;
			edge[u].push_back(make_pair(make_pair(v, c), d));
		}
		dijkstra(1);
		for (int j = 0; j < 10001; j++)
		{
			result = min(result, min_distance[N][j]);
		}
		if (result != INF)
			cout << result << '\n';
		else
			cout << "Poor KCM" << '\n';
	}
}