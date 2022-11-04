#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int start_pos, end_pos;
int N, M;

struct Node
{
	int x;
	long long cost;
};
vector<Node> edges[10001];
long long answer = 0;
bool visit[10001];

bool bfs(long long car_weight)
{
	queue<Node> q;
	q.push({ start_pos, 0 });
	visit[start_pos] = true;
	while (!q.empty())
	{
		int x = q.front().x;
		long long cost = q.front().cost;
		q.pop();
		for (int i = 0; i < edges[x].size(); i++)
		{
			int nx = edges[x][i].x;
			long long next_cost = edges[x][i].cost;
			if (!visit[nx] && car_weight <= next_cost)
			{
				q.push({ nx, next_cost });
				visit[nx] = true;
				if (nx == end_pos)
					return true;
			}
		}
	}
	return false;
}

void binary_search(long long left, long long right)
{
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		fill_n(visit, 10001, false);
		if (bfs(mid))
		{
			left = mid + 1;
			answer = max(answer, mid);
		}
		else
		{
			right = mid - 1;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	long long max_weight = 0;
	for(int i = 0; i < M; i++)
	{
		int A, B;
		long long C;
		cin >> A >> B >> C;
		edges[A].push_back({B, C});
		edges[B].push_back({A, C});
		max_weight = max(max_weight, C);
	}
	cin >> start_pos >> end_pos;
	binary_search(1, max_weight);
	cout << answer << '\n';
}