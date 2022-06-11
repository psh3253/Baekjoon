#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#define INF 987654321
using namespace std;
vector<pair<int, int>> edge[1001];
int d[1001];
int p[1001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	d[start] = 0;
	while(!pq.empty())
	{
		int x = pq.top().second;
		int distance = pq.top().first;
		pq.pop();

		if (distance > d[x])
			continue;
		for(int i = 0; i < edge[x].size(); i++)
		{
			int nx = edge[x][i].first;
			int next_distance = edge[x][i].second + distance;
			if(next_distance < d[nx])
			{
				d[nx] = next_distance;
				p[nx] = x;
				pq.push(make_pair(next_distance, nx));
			}
		}
	}
}

int main(void)
{
	fill_n(d, 1001, INF);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		edge[start].push_back(make_pair(end, cost));
	}
	int start_x, end_x;
	cin >> start_x >> end_x;
	dijkstra(start_x);
	cout << d[end_x] << '\n';
	stack<int> st;
	st.push(end_x);
	while(p[end_x] != 0)
	{
		st.push(p[end_x]);
		end_x = p[end_x];
	}
	cout << st.size() << '\n';
	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << '\n';
}