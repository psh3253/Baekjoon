#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;
int dis[10001];
int cnt, ts;

struct Node
{
	int pos;
	int distance;
};

struct compare
{
	bool operator()(Node& n1, Node& n2)
	{
		return n1.distance > n2.distance;
	}
};

vector<Node> edges[10001];

void dijkstra(int start)
{
	priority_queue<Node, vector<Node>, compare> pq;
	pq.push({ start, 0 });
	dis[start] = 0;
	while (!pq.empty())
	{
		int distance = pq.top().distance;
		int x = pq.top().pos;
		pq.pop();
		if (dis[x] < distance)
			continue;
		for (int i = 0; i < edges[x].size(); i++)
		{
			int nx = edges[x][i].pos;
			int next_distance = distance + edges[x][i].distance;
			if (next_distance < dis[nx])
			{
				pq.push({ nx, next_distance });
				dis[nx] = next_distance;
			}
		}
	}
}

int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cnt = 0;
		ts = 0;
		int n, d, c;
		cin >> n >> d >> c;
		fill_n(dis, n + 1, INF);
		for (int j = 1; j < n + 1; j++)
			edges[j].clear();
		for (int j = 0; j < d; j++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			edges[b].push_back({ a, s });
		}
		dijkstra(c);
		for (int j = 1; j < n + 1; j++)
		{
			if (dis[j] != INF)
				cnt++;
			if (dis[j] != INF)
				ts = max(ts, dis[j]);
		}
		cout << cnt << " " << ts << '\n';
	}
}