#include <iostream>
using namespace std;
int N, M;
int sequence[8];

void dfs(int length)
{
	if (length == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << sequence[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i < N + 1; i++)
	{
		sequence[length] = i;
		dfs(length + 1);
	}
}

int main(void)
{
	cin >> N >> M;
	dfs(0);
}