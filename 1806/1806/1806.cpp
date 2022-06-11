#include <iostream>
using namespace std;
int arr[100000];

int main(void)
{
	int answer = 987654321;
	int N, S;
	cin >> N >> S;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int start = 0;
	int end = 0;
	int partial_sum = 0;
	while(end <= N)
	{
		if(partial_sum < S)
		{
			partial_sum += arr[end++];
		}
		else
		{
			answer = min(answer, end - start);
			partial_sum -= arr[start++];
		}
	}
	if (answer == 987654321)
		cout << 0 << '\n';
	else
		cout << answer << '\n';
}