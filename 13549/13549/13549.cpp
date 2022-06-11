#include <iostream>
#include <deque>
using namespace std;
int visit[100001];

int bfs(int N, int K)
{
	deque<int> dq;
	dq.push_front(N);
	visit[N] = 0;
	while(!dq.empty())
	{
		int x = dq.front();
		if (x == K)
			return visit[x];
		dq.pop_front();
		if (x * 2 <= 100000 && visit[x * 2] == -1)
		{
			visit[x * 2] = visit[x];
			dq.push_front(x * 2);
		}
		if(x - 1 > -1 && visit[x - 1] == -1)
		{
			visit[x - 1] = visit[x] + 1;
			dq.push_back(x - 1);
		}
		if(x + 1 <= 100000 && visit[x + 1] == -1)
		{
			visit[x + 1] = visit[x] + 1;
			dq.push_back(x + 1);
		}
	}
}

int main(void)
{
	fill_n(visit, 100001, -1);
	int N, K;
	cin >> N >> K;
	int answer = bfs(N, K);
	cout << answer << '\n';
}