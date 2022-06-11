#include <iostream>
using namespace std;
int arr[1001];
int memo[1001];

int main(void)
{
	int N;
	cin >> N;
	for(int i = 1; i < N + 1; i++)
	{
		cin >> arr[i];
	}
	for(int i = 1; i < N + 1; i++)
	{
		memo[i] = arr[i];
		for(int j = 1; j < i / 2 + 1; j++)
		{
			memo[i] = max(memo[i], memo[j] + memo[i - j]);
		}
	}
	cout << memo[N] << '\n';
}