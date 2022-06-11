#include <iostream>
using namespace std;
int answer = 987654321;
int W[10][10];
bool visit[10];
int start;

void backtracking(int r, int n, int distance, int parent)
{
	if(r == n)
	{
		if(W[parent][start] != 0)
			answer = min(answer, distance + W[parent][start]);
		return;
	}
	for(int i = 0; i < n; i++)
	{
		if(!visit[i] && (W[parent][i] != 0 || parent == n))
		{
			visit[i] = true;
			if (r == 0)
				start = i;
			backtracking(r + 1, n, distance + W[parent][i], i);
			visit[i] = false;
		}
	}
}

int main(void)
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}
	backtracking(0, N, 0, N);
	cout << answer << '\n';
}