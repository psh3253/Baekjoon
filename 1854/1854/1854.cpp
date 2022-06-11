#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, K;

struct Node
{
	int x;
	int cost;
};

priority_queue<int> city_pq[1001];
vector<Node> edge[1001];

struct compare
{
	bool operator()(Node &node1, Node &node2)
	{
		return node1.cost > node2.cost;
	}
};

void dijkstra(int start)
{
	priority_queue<Node, vector<Node>, compare> pq;
	pq.push({ start, 0 });
	city_pq[start].push(0);
	while(!pq.empty())
	{
		int x = pq.top().x;
		int cost = pq.top().cost;
		pq.pop();
		for(int i = 0; i < edge[x].size(); i++)
		{
			int nx = edge[x][i].x;
			int next_cost = edge[x][i].cost + cost;
			if (city_pq[nx].size() < K)
			{
				city_pq[nx].push({ next_cost });
				pq.push({ nx, next_cost });
			}
			else
			{
				if(next_cost < city_pq[nx].top())
				{
					city_pq[nx].pop();
					city_pq[nx].push({ next_cost });
					pq.push({ nx, next_cost });
				}
			}
		}
	}
}

int main(void)
{
	cin >> N >> M >> K;
	for(int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
	}
	dijkstra(1);
	for(int i = 1; i < N + 1; i++)
	{
		if (city_pq[i].size() == K)
		{
			cout << city_pq[i].top() << '\n';
		}
		else
			cout << -1 << '\n';
	}
}