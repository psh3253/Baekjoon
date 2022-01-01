#include <iostream>
using namespace std;
int N;
int arr[8];
int temp_arr[8];
bool visit[8];
int answer;

void backtracking(int r, int n)
{
	if(r == n)
	{
		int sum = 0;
		for(int i = 0; i < N - 1; i ++)
		{
			sum += abs(temp_arr[i] - temp_arr[i + 1]);
			answer = max(answer, sum);
		}
		return;
	}
	for(int i = 0; i < N; i++)
	{
		if(!visit[i])
		{
			visit[i] = true;
			temp_arr[r] = arr[i];
			backtracking(r + 1, n);
			visit[i] = false;
		}
	}
}

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	backtracking(0, N);
	cout << answer << '\n';
}