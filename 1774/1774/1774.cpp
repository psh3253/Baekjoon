#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<pair<int, int>> vertex;
int p[1001];

struct Node
{
	int start;
	int end;
	double distance;
};

struct compare {
	bool operator()(Node& n1, Node& n2)
	{
		return n1.distance < n2.distance;
	}
};

vector<Node> edges;


int get_parent(int x)
{
	if (x == p[x])
		return x;
	return p[x] = get_parent(p[x]);
}

void union_parent(int x, int y)
{
	int parent_x = get_parent(x);
	int parent_y = get_parent(y);
	if (parent_x < parent_y)
		p[parent_y] = parent_x;
	else
		p[parent_x] = parent_y;
}

double kruskal()
{
	double answer = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		if (get_parent(edges[i].start) != get_parent(edges[i].end))
		{
			union_parent(edges[i].start, edges[i].end);
			answer += edges[i].distance;
		}
	}
	return answer;
}

int main(void)
{
	for (int i = 1; i < 1001; i++)
		p[i] = i;
	int N, M;
	cin >> N >> M;
	vertex.push_back({ 0, 0 });
	for (int i = 1; i < N + 1; i++)
	{
		int x, y;
		cin >> x >> y;
		vertex.push_back({ x, y });
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		union_parent(a, b);
	}

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			if (i == j)
				continue;
			pair<int, int> pos1 = vertex[i];
			pair<int, int> pos2 = vertex[j];
			double distance = sqrt(pow(pos1.first - pos2.first, 2) + pow(pos1.second - pos2.second, 2));
			edges.push_back({ i, j, distance });
		}
	}
	sort(edges.begin(), edges.end(), compare());
	printf("%.2lf\n", kruskal());
}