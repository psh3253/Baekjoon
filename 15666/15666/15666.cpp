#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int answer[8];
int arr[8];
vector<int> arr_v;

void backtracking(int cur, int n, int m, int prev)
{
	if (cur == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < arr_v.size(); i++)
	{
		if (prev <= arr_v[i])
		{
			answer[cur] = arr_v[i];
			backtracking(cur + 1, n, m, arr_v[i]);
		}
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int prev = -1;
	for (int i = 0; i < n; i++)
	{
		if (prev != arr[i])
			arr_v.push_back(arr[i]);
		prev = arr[i];
	}
	backtracking(0, n, m, -1);
}
