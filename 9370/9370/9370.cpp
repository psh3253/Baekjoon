#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define INF 30000000
using namespace std;
vector<pair<int, int>> road[2001];
vector<int> destination;
vector<int> result;
int min_distance[2001];
int v2_end[2001];
int v1_end[2001];

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
		for (int i = 0; i < road[current].size(); i++)
		{
			next = road[current][i].first;
			next_distance = road[current][i].second + current_distance;
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
	int T;
	int crossload_count, road_count, destination_count;
	int start, v1, v2;
	int a, b, d;
	int v1_v2 = INF;
	int temp;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> crossload_count >> road_count >> destination_count;
		cin >> start >> v1 >> v2;
		for (int j = 1; j < crossload_count + 1; j++)
		{
			road[j].clear();
		}
		fill(min_distance, min_distance + crossload_count + 1, INF);
		fill(v1_end, v1_end + crossload_count + 1, INF);
		fill(v2_end, v2_end + crossload_count + 1, INF);
		destination.clear();
		result.clear();

		for (int j = 0; j < road_count; j++)
		{
			cin >> a >> b >> d;
			road[a].push_back(make_pair(b, d));
			road[b].push_back(make_pair(a, d));
			if (a == v1 && b == v2 || a == v2 && b == v1)
				v1_v2 = d;
		}
		for (int j = 0; j < destination_count; j++)
		{
			cin >> temp;
			destination.push_back(temp);
		}
		dijkstra(v1);
		copy(min_distance, min_distance + crossload_count + 1, v1_end);

		fill(min_distance, min_distance + crossload_count + 1, INF);
		dijkstra(v2);
		copy(min_distance, min_distance + crossload_count + 1, v2_end);

		fill(min_distance, min_distance + crossload_count + 1, INF);
		dijkstra(start);
		for (int j = 0; j < destination.size(); j++)
		{
			if (min_distance[destination[j]] == min_distance[v1] + v1_v2 + v2_end[destination[j]])
			{
				result.push_back(destination[j]);
			}
			else if (min_distance[destination[j]] == min_distance[v2] + v1_v2 + v1_end[destination[j]])
			{
				result.push_back(destination[j]);
			}
		}
		sort(result.begin(), result.end());
		for (int j = 0; j < result.size(); j++)
		{
			cout << result[j] << ' ';
		}
		cout << '\n';
	}
}