#include <iostream>
using namespace std;

int arr[1001][1001];
int memo[1001][1001];

int main(void)
{
	int N, M;
	cin >> N >> M;
	for(int i = 1; i < N + 1; i++)
	{
		for(int j = 1; j < M + 1; j++)
		{
			cin >> arr[i][j];
		}
	}
	for(int i = 1; i < N + 1; i++)
	{
		for(int j = 1; j < M + 1; j++)
		{
			memo[i][j] = max(memo[i - 1][j] + arr[i][j], memo[i - 1][j - 1] + arr[i][j]);
			memo[i][j] = max(memo[i][j], memo[i][j - 1] + arr[i][j]);
		}
	}
	cout << memo[N][M] << '\n';
}