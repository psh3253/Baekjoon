#include <algorithm>
#include <iostream>
using namespace std;
int M, N;
int arr[8];
int temp_arr[8];
int prev_arr[8];
bool visit[8];

void backtracking(int r, int n)
{
	if (r == n)
	{
		for (int i = 0; i < M; i++)
		{
			cout << temp_arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	int prev = 0;
	for (int i = 0; i < N; i++)
	{
		if (!visit[i] && (prev == 0 || prev != arr[i]))
		{
			temp_arr[r] = arr[i];
			visit[i] = true;
			backtracking(r + 1, n);
			visit[i] = false;
			prev = arr[i];
		}
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	backtracking(0, M);
}