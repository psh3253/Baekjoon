#include <algorithm>
#include <iostream>
using namespace std;
int arr[8];
int temp_arr[8];

void backtracking(int r, int n, int size)
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
	for(int i = 0; i < size; i++)
	{
		if(r >= 1 && arr[i] < temp_arr[r - 1])
		{
			continue;
		}
		temp_arr[r] = arr[i];
		backtracking(r + 1, n, size);
	}
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	backtracking(0, M, N);
}