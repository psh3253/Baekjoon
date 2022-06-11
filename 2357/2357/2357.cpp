#include <iostream>
using namespace std;

int min_tree[400000];
int max_tree[400000];
int arr[100000];

int init_min(int start, int end, int node)
{
	if(start == end)
	{
		return min_tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return min_tree[node] = min(init_min(start, mid, node * 2), init_min(mid + 1, end, node * 2 + 1));
}

int init_max(int start, int end, int node)
{
	if (start == end)
	{
		return max_tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return max_tree[node] = max(init_max(start, mid, node * 2), init_max(mid + 1, end, node * 2 + 1));
}

int get_min(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 2000000000;
	if (left <= start && end <= right)
		return min_tree[node];
	int mid = (start + end) / 2;
	return min(get_min(start, mid, node * 2, left, right), get_min(mid + 1, end, node * 2 + 1, left, right));
}

int get_max(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return max_tree[node];
	int mid = (start + end) / 2;
	return max(get_max(start, mid, node * 2, left, right), get_max(mid + 1, end, node * 2 + 1, left, right));
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
	init_min(0, N - 1, 1);
	init_max(0, N - 1, 1);
	for(int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << get_min(0, N - 1, 1, a - 1, b - 1) << " " << get_max(0, N - 1, 1, a - 1, b - 1) << '\n';
	}
	
}