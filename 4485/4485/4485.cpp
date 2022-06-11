#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int map[125][125];
int d[125][125];

void bfs_dijkstra(int N)
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push(make_pair(map[0][0], make_pair(0, 0)));
	d[0][0] = map[0][0];
	while(!pq.empty())
	{
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int distance = pq.top().first;
		pq.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int next_distance = distance + map[ny][nx];
			if (nx < 0 || ny < 0 || nx >= N && ny >= N)
				continue;
			if(next_distance < d[ny][nx])
			{
				d[ny][nx] = next_distance;
				pq.push(make_pair(next_distance, make_pair(nx, ny)));
			}
		}
	}
}

int main(void)
{
	int count = 1;
	while(true)
	{
		int N;
		cin >> N;
		if (N == 0)
			break;
		for(int i = 0; i < N; i++)
		{
			fill_n(d[i], N, INF);
			for(int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}
		bfs_dijkstra(N);
		cout << "Problem " << count << ": " << d[N - 1][N - 1] << '\n';
		count++;
	}
}