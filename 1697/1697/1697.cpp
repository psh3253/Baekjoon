#include <iostream>
#include <queue>
using namespace std;
int pos[100001];
bool visit[100001];

void bfs(int x)
{
	int tx, nx;
	queue<int> q;
	q.push(x);
	visit[x] = true;
	while (!q.empty())
	{
		tx = q.front();
		q.pop();
		nx = tx + 1;
		if (nx > -1 && nx < 100001 && !visit[nx])
		{
			q.push(nx);
			visit[nx] = true;
			pos[nx] = pos[tx] + 1;
		}
		nx = tx - 1;
		if (nx > -1 && nx < 100001 && !visit[nx])
		{
			q.push(nx);
			visit[nx] = true;
			pos[nx] = pos[tx] + 1;
		}
		nx = tx * 2;
		if (nx > -1 && nx < 100001 && !visit[nx])
		{
			q.push(nx);
			visit[nx] = true;
			pos[nx] = pos[tx] + 1;
		}
	}
}

int main(void)
{
	int N, K;
	cin >> N >> K;
	bfs(N);
	cout << pos[K] << endl;
}