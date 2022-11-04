#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int p[200001];

struct Node
{
	int x;
	int y;
	int distance;
};

vector<Node> edges;

struct compare {
	bool operator()(Node& n1, Node& n2)
	{
		return n1.distance < n2.distance;
	}
};

int get_parent(int x)
{
	if (x == p[x])
		return x;
	return p[x] = get_parent(p[x]);
}

void union_parent(int x, int y)
{
	int x_parent = get_parent(x);
	int y_parent = get_parent(y);
	if (x_parent < y_parent)
		p[y_parent] = x_parent;
	else
		p[x_parent] = y_parent;
}

int kruskal()
{
	int answer = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int x = edges[i].x;
		int y = edges[i].y;
		int distance = edges[i].distance;
		if (get_parent(x) != get_parent(y))
		{
			union_parent(x, y);
		}
		else
			answer += distance;
	}
	return answer;
}

int main(void)
{
	while (true)
	{
		edges.clear();
		int m, n;
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;
		for (int i = 0; i <= m; i++)
			p[i] = i;
		for (int i = 0; i < n; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({ x, y, z });
		}
		sort(edges.begin(), edges.end(), compare());
		cout << kruskal() << '\n';
	}
}