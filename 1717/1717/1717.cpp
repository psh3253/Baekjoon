#include <iostream>
using namespace std;
int arr[1000001];

int get_parent(int x)
{
	if (x == arr[x])
	{
		return x;
	}
	else
	{
		return arr[x] = get_parent(arr[x]);
	}
}

void union_set(int x, int y)
{
	int x_parent = get_parent(x);
	int y_parent = get_parent(y);
	if (x_parent < y_parent)
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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int command, a, b;
		cin >> command >> a >> b;
		if (command == 0)
		{
			union_set(a, b);
		}
		else
		{
			if (get_parent(a) == get_parent(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}
}