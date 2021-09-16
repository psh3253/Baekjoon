#include <iostream>
using namespace std;
int N, M;
int sequence[9];
bool visit[9];

void dfs(int cnt)
{
	if(cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << sequence[i] << " ";
		cout << "\n";
		return;
	}
	for(int i = 1; i < N + 1; i++)
	{
		if(!visit[i])
		{
			sequence[cnt] = i;
			visit[i] = true;
			dfs(cnt + 1);
			visit[i] = false;
		}
	}
}

int main(void)
{
	cin >> N >> M;
	dfs(0);
}