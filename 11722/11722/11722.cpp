#include <iostream>
using namespace std;
int memo[1001];
int arr[1001];

int main(void)
{
	int answer = 0;
	int N;
	cin >> N;
	for(int i = 1; i < N + 1; i++)
	{
		cin >> arr[i];
		memo[i] = 1;
	}
	for(int i = 1; i < N + 1; i++)
	{
		for(int j = i + 1; j < N + 1; j++)
		{
			if (arr[j] < arr[i])
				memo[j] = max(memo[j], memo[i] + 1);
		}
	}
	for(int i = 1; i < N + 1; i++)
	{
		answer = max(answer, memo[i]);
	}
	cout << answer << '\n';
}