#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[8];
int visit[8];
int temp_arr[8];

void backtracking(int r, int n)
{
	if(r == n)
	{
		for(int i = 0; i < n; i++)
		{
			cout << temp_arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for(int i = 0; i < N; i++)
	{
		if(!visit[i])
		{
			temp_arr[r] = arr[i];
			visit[i] = true;
			backtracking(r + 1, n);
			visit[i] = false;
		}
	}
}

int main(void)
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	backtracking(0, M);
}