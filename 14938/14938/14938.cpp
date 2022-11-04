#include <iostream>
#include <vector>
#include <queue>
#define INF 9887654321
using namespace std;

struct Node {
	int x;
	int distance;
};

struct compare
{
	bool operator()(Node& n1, Node& n2)
	{
		return n1.distance > n2.distance;
	}
};

int item_count[101];
int d[101];
vector<Node> edges[101];

void dijkstra(int start)
{
	priority_queue<Node, vector<Node>, compare> pq;
	pq.push({ start, 0 });
	d[start] = 0;
	while (!pq.empty())
	{
		int x = pq.top().x;
		int distance = pq.top().distance;
		pq.pop();
		for (int i = 0; i < edges[x].size(); i++)
		{
			int nx = edges[x][i].x;
			int next_distance = edges[x][i].distance + distance;
			if (next_distance < d[nx])
			{
				pq.push({ nx, next_distance });
				d[nx] = next_distance;
			}
		}
	}
}

int main(void)
{
	int answer = 0;
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i < n + 1; i++)
		cin >> item_count[i];
	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		edges[a].push_back({ b, l });
		edges[b].push_back({ a, l });
	}
	for (int i = 1; i < n + 1; i++)
	{
		fill_n(d, n + 1, INF);
		int total = 0;
		dijkstra(i);
		for (int j = 1; j < n + 1; j++)
		{
			if (d[j] != INF && d[j] <= m)
				total += item_count[j];
		}
		answer = max(answer, total);
	}
	cout << answer << '\n';
}