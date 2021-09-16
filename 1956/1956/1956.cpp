#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define INF 987654321
using namespace std;
int road[401][401];

int main(void)
{
	int V, E;
	int source, destination, distance;
	int min_distance = INF;
	cin >> V >> E;
	for (int i = 0; i < V + 1; i++)
	{
		fill(road[i], road[i] + V + 1, INF);
		road[i][i] = 0;
	}
	for (int i = 0; i < E; i++)
	{
		cin >> source >> destination >> distance;
		road[source][destination] = distance;
	}

	for(int i = 1; i < V + 1; i++)
	{
		for(int j = 1; j < V + 1; j++)
		{
			if(i == j)
				continue;
			for(int k = 1; k < V + 1; k++)
			{
				if(i == k || j == k)
					continue;
				if (road[j][i] + road[i][k] < road[j][k])
					road[j][k] = road[j][i] + road[i][k];
			}
		}
	}

	for(int i = 1; i < V + 1; i++)
	{
		for(int j = 1; j < V + 1; j++)
		{
			if(i == j)
				continue;
			if (road[i][j] != INF && road[j][i] != INF && road[i][j] + road[j][i] < min_distance)
				min_distance = road[i][j] + road[j][i];
		}
	}
	if (min_distance == INF)
		cout << -1 << "\n";
	else
		cout << min_distance << "\n";
}