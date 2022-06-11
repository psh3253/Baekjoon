#include <iostream>
using namespace std;
int arr[1001];
int memo[1001];

int main(void)
{
	int answer = 0;
	int N;
	cin >> N;
	for(int i = 1; i < N + 1; i++)
	{
		cin >> arr[i];
		memo[i] = arr[i];
	}
	for(int i = 1; i < N + 1; i++)
	{
		for(int j = 1; j < i; j++)
		{
			if(arr[i] > arr[j])
			{
				memo[i] = max(memo[i], memo[j] + arr[i]);
			}
		}
		answer = max(memo[i], answer);
	}
	cout << answer << '\n';
}