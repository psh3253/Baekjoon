#include <iostream>
using namespace std;
int arr[8];
int temp_arr[8];
bool visit[8];

void backtracking(int r, int n)
{
	if(r == n)
	{
		for(int i = 0; i < n; i++)
		{
			cout << temp_arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = 0; i < n; i++)
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
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		arr[i] = i + 1;
	}
	backtracking(0, N);
}