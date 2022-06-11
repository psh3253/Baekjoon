#include <iostream>
using namespace std;
int arr[100000];
int tree[400000];

int init(int start, int end, int node)
{
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int get_min(int start, int end, int node, int left, int right)
{
	if (right < start || end < left)
		return 2000000000;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return min(get_min(start, mid, node * 2, left, right), get_min(mid + 1, end, node * 2 + 1, left, right));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	init(0, N - 1, 1);
	for(int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << get_min(0, N - 1, 1, a - 1, b - 1) << '\n';
	}
}