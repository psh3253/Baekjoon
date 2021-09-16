#include <iostream>
using namespace std;
int N, M;
int sequence[9];
int visit[9];

void dfs(int length)
{
	if (length == M)
	{
		for (int i = 0; i < M; i++)
			cout << sequence[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (!visit[i])
		{
			if (length == 0 || sequence[length - 1] < i)
			{
				sequence[length] = i;
				visit[i] = true;
				dfs(length + 1);
				visit[i] = false;
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	dfs(0);
}