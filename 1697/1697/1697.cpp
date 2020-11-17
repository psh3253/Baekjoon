#include <iostream>
#include <queue>
using namespace std;

int road[100001] = { 0, };
bool visit[100001] = { false, };
int c[100001] = { 0, };
queue<int> q;

void bfs(int start)
{
	q.push(start);
	visit[start] = true;
	while (!q.empty())
	{
		int pos = q.front();
		q.pop();
		if (road[pos] == 1)
		{
			cout << c[pos] << endl;
			return;
		}
		int npos = pos - 1;
		if (npos > -1 && npos < 100001 && !visit[npos])
		{
			q.push(npos);
			visit[npos] = true;
			c[npos] = c[pos] + 1;
		}
		npos = pos + 1;
		if (npos > -1 && npos < 100001 && !visit[npos])
		{
			q.push(npos);
			visit[npos] = true;
			c[npos] = c[pos] + 1;
		}
		npos = pos * 2;
		if (npos > -1 && npos < 100001 && !visit[npos])
		{
			q.push(npos);
			visit[npos] = true;
			c[npos] = c[pos] + 1;
		}
	}
}

int main(void)
{
	int x, y;
	cin >> x >> y;
	road[y] = 1;
	bfs(x);
	return 0;
}