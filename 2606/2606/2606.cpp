#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visit[101] = { false, };
vector<int> edge[101];

int bfs()
{
	int x, y, sum = 0;
	queue<int> queue;
	queue.push(1);
	visit[1] = true;
	while (!queue.empty())
	{
		x = queue.front();
		queue.pop();
		sum++;
		for (int i = 0; i < edge[x].size(); i++)
		{
			y = edge[x][i];
			if (!visit[y])
			{
				queue.push(y);
				visit[y] = true;
			}
		}
	}
	return sum;
}

int main(void)
{
	int computer_count, edge_count, x, y;
	cin >> computer_count;
	cin >> edge_count;
	for (int i = 0; i < edge_count; i++)
	{
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	cout << bfs() - 1 << endl;
}