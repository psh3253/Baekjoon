#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int x;
	int y;
	int cost;
};

struct compare
{
	bool operator()(Node &node1, Node &node2)
	{
		return node1.cost > node2.cost;
	}
};

int n;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int map[50][50];
bool visit[50][50];
priority_queue<Node, vector<Node>, compare> pq;

int bfs(int start_x, int start_y, int start_cost)
{
	pq.push({ start_x, start_y, start_cost });
	visit[start_y][start_x] = true;
	while(!pq.empty())
	{
		int x = pq.top().x;
		int y = pq.top().y;
		int cost = pq.top().cost;
		pq.pop();
		if (x == n - 1 && y == n - 1)
			return cost;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >=  n)
				continue;
			if(!visit[ny][nx])
			{
				if(map[ny][nx] == 1)
				{
					pq.push({ nx, ny, cost});
					visit[ny][nx] = true;
				}
				else
				{
					pq.push({ nx, ny, cost + 1 });
					visit[ny][nx] = true;
				}
			}
		}
	}
	return 0;
}

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0 ;j < n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	int answer = bfs(0, 0, 0);
	cout << answer << '\n';
}