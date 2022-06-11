#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int set[10000];
vector<pair<int, pair<int, int>>> edge;

int get_parent(int x)
{
	if (set[x] == x)
		return x;
	return set[x] = get_parent(set[x]);
}

void union_set(int x, int y)
{
	int x_parent = get_parent(x);
	int y_parent = get_parent(y);
	if (x_parent < y_parent)
	{
		set[y_parent] = x_parent;
	}
	else
	{
		set[x_parent] = y_parent;
	}
}

int kruskal()
{
	int temp = 0;
	for (int i = 0; i < edge.size(); i++)
	{
		int start = edge[i].second.first;
		int end = edge[i].second.second;
		int cost = edge[i].first;
		if (get_parent(start) != get_parent(end))
		{
			union_set(start, end);
			temp += cost;
		}
	}
	return temp;
}

int main(void)
{
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		edge.push_back(make_pair(cost, make_pair(start, end)));
	}
	for (int i = 1; i < V + 1; i++)
	{
		set[i] = i;
	}
	sort(edge.begin(), edge.end());
	cout << kruskal() << '\n';
}