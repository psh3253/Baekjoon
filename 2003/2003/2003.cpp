#include <iostream>
using namespace std;
int arr[10000];

int main(void)
{
	int answer = 0;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int start = 0;
	int end = 0;
	int partial_sum = 0;
	while(end <= N)
	{
		if(partial_sum < M)
		{
			partial_sum += arr[end++];
		}
		else if(partial_sum >= M)
		{
			if (partial_sum == M)
				answer++;
			partial_sum -= arr[start++];
		}
	}
	cout << answer << '\n';
}