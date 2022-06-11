#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<double, pair<int, int>>> edge;
vector<pair<double, double>> vertex;
int set[101];

int get_parent(int x)
{
	if (x == set[x])
		return x;
	else
		return set[x] = get_parent(set[x]);
}

void union_parent(int x, int y)
{
	int x_parent = get_parent(x);
	int y_parent = get_parent(y);
	if (x_parent < y_parent)
		set[y_parent] = x_parent;
	else
		set[x_parent] = y_parent;
}

double kruskal()
{
	double answer = 0;
	for (int i = 0; i < edge.size(); i++)
	{
		double cost = edge[i].first;
		int start = edge[i].second.first;
		int end = edge[i].second.second;
		if (get_parent(start) != get_parent(end))
		{
			union_parent(start, end);
			answer += cost;
		}
	}
	return answer;
}

int main(void)
{
	int n;
	cin >> n;
	double previous_x, previous_y;
	for (int i = 1; i < n + 1; i++)
	{
		double x, y;
		cin >> x >> y;
		vertex.push_back(make_pair(x, y));
		for(int j = 1; j < i; j++)
		{
			double x_distance = abs(vertex[j-1].first - vertex[i - 1].first);
			double y_distance = abs(vertex[j-1].second - vertex[i - 1].second);
			edge.push_back(make_pair(sqrt(pow(x_distance, 2) + pow(y_distance, 2)), make_pair(i, j)));
		}
		set[i] = i;
	}
	sort(edge.begin(), edge.end());
	cout << kruskal() << '\n';
}