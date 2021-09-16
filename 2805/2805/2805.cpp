#include <iostream>
using namespace std;
long long tree[1000001];

int main(void)
{
	int max_height = 0;
	long long tree_height;
	long long low = 0, mid, high = 1;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
		if (tree[i] >= high)
			high = tree[i];
	}
	while (low <= high)
	{
		mid = (low + high) / 2;
		tree_height = 0;
		for (int i = 0; i < N; i++)
		{
			if (tree[i] > mid)
				tree_height += tree[i] - mid;
		}
		if (tree_height >= M)
		{
			if (mid > max_height)
				max_height = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << max_height << '\n';
}