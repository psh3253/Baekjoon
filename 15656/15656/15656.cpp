#include <algorithm>
#include <iostream>
using namespace std;
int arr[8];
int temp_arr[8];
int N, M;

void backtracking(int r, int n)
{
	if (r == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << temp_arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		temp_arr[r] = arr[i];
		backtracking(r + 1, n);
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