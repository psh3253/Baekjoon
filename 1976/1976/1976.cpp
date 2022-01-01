#include <iostream>
using namespace std;
int arr[201];
int destination[1001];

int get_parent(int x)
{
	if (x == arr[x])
		return x;
	return arr[x] = get_parent(arr[x]);
}

void union_set(int x, int y)
{
	int x_parent = get_parent(x);
	int y_parent = get_parent(y);
	if(x_parent < y_parent)
	{
		arr[y_parent] = x_parent;
	}
	else
	{
		arr[x_parent] = y_parent;
	}
}

int main(void)
{
	int N, M;
	cin >> N;
	cin >> M;
	for (int i = 1; i < N + 1; i++)
		arr[i] = i;
	for(int i = 1; i < N + 1; i++)
	{
		for(int j = 1; j < N + 1; j++)
		{
			int connection;
			cin >> connection;
			if(connection == 1)
			{
				union_set(i, j);
			}
		}
	}
	for(int i = 0; i < M; i++)
	{
		cin >> destination[i];
	}
	for(int i = 0; i < M - 1; i++)
	{
		if (get_parent(destination[i]) != get_parent(destination[i + 1]))
		{
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
	return 0;
}