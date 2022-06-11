#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int set[1001];
vector<pair<int, int>> red_edge;
vector<pair<int, int>> blue_edge;

int get_parent(int x)
{
	if (set[x] == x)
		return x;
	return set[x] = get_parent(set[x]);
}

void union_parent(int x, int y)
{
	int parent_x = get_parent(x);
	int parent_y = get_parent(y);
	if (parent_x < parent_y)
		set[parent_y] = parent_x;
	else
		set[parent_x] = parent_y;
}

int kruskal(bool mode)
{
	int blue_edge_count = 0;
	if(!mode)
	{
		for (int i = 0; i < red_edge.size(); i++)
		{
			int x = red_edge[i].first;
			int y = red_edge[i].second;
			if (get_parent(x) != get_parent(y))
			{
				union_parent(x, y);
			}
		}
		for (int i = 0; i < blue_edge.size(); i++)
		{
			int x = blue_edge[i].first;
			int y = blue_edge[i].second;
			if (get_parent(x) != get_parent(y))
			{
				union_parent(x, y);
				blue_edge_count++;
			}
		}
	}
	else
	{
		for (int i = 0; i < blue_edge.size(); i++)
		{
			int x = blue_edge[i].first;
			int y = blue_edge[i].second;
			if (get_parent(x) != get_parent(y))
			{
				union_parent(x, y);
				blue_edge_count++;
			}
		}
		for (int i = 0; i < red_edge.size(); i++)
		{
			int x = red_edge[i].first;
			int y = red_edge[i].second;
			if (get_parent(x) != get_parent(y))
			{
				union_parent(x, y);
			}
		}
	}
	return blue_edge_count;
}

int main(void)
{
	while(true)
	{
		int min_blue_edge_count = 0;
		int max_blue_edge_count = 0;
		int n, m, k;
		cin >> n >> m >> k;
		if (n == 0 && m == 0 && k == 0)
			break;
		red_edge.clear();
		blue_edge.clear();
		for(int i = 0; i < m; i++)
		{
			char edge_type;
			int start, end;
			cin >> edge_type >> start >> end;
			if(edge_type == 'B')
			{
				blue_edge.push_back(make_pair(start, end));
			}
			else
			{
				red_edge.push_back(make_pair(start, end));
			}
		}
		sort(blue_edge.begin(), blue_edge.end());
		sort(red_edge.begin(), red_edge.end());
		for (int i = 1; i < n + 1; i++)
			set[i] = i;
		min_blue_edge_count = kruskal(false);
		for (int i = 1; i < n + 1; i++)
			set[i] = i;
		max_blue_edge_count = kruskal(true);
		if (k >= min_blue_edge_count && k <= max_blue_edge_count)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}