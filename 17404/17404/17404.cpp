#include <iostream>
#include <cstring>
using namespace std;
int arr[1000][3];
int memo[1000][3];

int main(void)
{
	int answer = 987654321;
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if (i == j)
				memo[0][j] = arr[0][j];
			else
				memo[0][j] = 987654321;
		}
		for(int j = 1; j < N; j++)
		{
			memo[j][0] = min(memo[j - 1][1] + arr[j][0], memo[j - 1][2] + arr[j][0]);
			memo[j][1] = min(memo[j - 1][0] + arr[j][1], memo[j - 1][2] + arr[j][1]);
			memo[j][2] = min(memo[j - 1][0] + arr[j][2], memo[j - 1][1] + arr[j][2]);
		}
		for(int j = 0;j < 3; j++)
		{
			if (i != j)
				answer = min(answer, memo[N - 1][j]);
		}
	}
	cout << answer << '\n';
}