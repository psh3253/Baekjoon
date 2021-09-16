#include <iostream>
#include <vector>
#include <utility>
#define INF 6000000
using namespace std;
vector<pair<int, int>> edge[501];
long long min_distance[501];

int main(void)
{
	bool cycle = false;
	int N, M, source, destination, time, next;
	long long next_distance;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> source >> destination >> time;
		edge[source].push_back(make_pair(destination, time));
	}
	fill(min_distance, min_distance + N + 1, INF);
	min_distance[1] = 0;
	for (int i = 0; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			for (int k = 0; k < edge[j].size(); k++)
			{
				next = edge[j][k].first;
				next_distance = edge[j][k].second + min_distance[j];
				if (min_distance[j] != INF && next_distance < min_distance[next])
				{
					min_distance[next] = next_distance;
					if (i == N)
						cycle = true;
				}
			}
		}
	}
	if (cycle)
		cout << -1 << '\n';
	else {
		for (int i = 2; i < N + 1; i++)
		{
			if (min_distance[i] == INF)
				cout << -1 << '\n';
			else
				cout << min_distance[i] << '\n';
		}
	}
}