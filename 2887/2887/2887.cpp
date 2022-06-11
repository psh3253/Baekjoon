#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int set[100001];
vector <pair<int, int>> x_vertex;
vector <pair<int, int>> y_vertex;
vector <pair<int, int>> z_vertex;
vector<pair<int, pair<int, int>>> edge;

int get_parent(int x)
{
	if (x == set[x])
		return x;
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

int kruskal()
{
	int answer = 0;
	for (int i = 0; i < edge.size(); i++)
	{
		int cost = edge[i].first;
		int start = edge[i].second.first;
		int end = edge[i].second.second;
		if(get_parent(start) != get_parent(end))
		{
			answer += cost;
			union_parent(start, end);
		}
	}
	return answer;
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i < N + 1; i++)
		set[i] = i;
	for (int i = 1; i < N + 1; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		x_vertex.push_back(make_pair(x, i));
		y_vertex.push_back(make_pair(y, i));
		z_vertex.push_back(make_pair(z, i));
	}
	sort(x_vertex.begin(), x_vertex.end());
	sort(y_vertex.begin(), y_vertex.end());
	sort(z_vertex.begin(), z_vertex.end());
	for (int i = 1; i < N; i++)
	{
		edge.push_back(make_pair(abs(x_vertex[i].first - x_vertex[i - 1].first), make_pair(x_vertex[i - 1].second, x_vertex[i].second)));
		edge.push_back(make_pair(abs(y_vertex[i].first - y_vertex[i - 1].first), make_pair(y_vertex[i - 1].second, y_vertex[i].second)));
		edge.push_back(make_pair(abs(z_vertex[i].first - z_vertex[i - 1].first), make_pair(z_vertex[i - 1].second, z_vertex[i].second)));
	}
	sort(edge.begin(), edge.end());
	cout << kruskal() << '\n';
}