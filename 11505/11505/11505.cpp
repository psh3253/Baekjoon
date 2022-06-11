#include <iostream>
using namespace std;
int arr[1000000];
long long tree[4000000];

long long init(int start, int end, int node)
{
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1) % 1000000007;
}

long long get_mul(int start, int end, int node, int left, int right)
{
	if (right < start || end < left)
		return 1;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return get_mul(start, mid, node * 2, left, right) * get_mul(mid + 1, end, node * 2 + 1, left, right) % 1000000007;
}

long long update(int start, int end, int node, int idx, int num)
{
	if (idx < start || idx > end)
		return tree[node];
	if(start == end)
		return tree[node] = num;
	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, node * 2, idx, num) * update(mid + 1, end, node * 2 + 1, idx, num) % 1000000007;
}

int main(void)
{
	int N, M, K;
	cin >> N >> M >> K;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	init(0, N - 1, 1);
	for(int i = 0; i < M + K; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1)
		{
			update(0, N - 1, 1, b - 1, c);
		}
		else
		{
			cout << get_mul(0, N - 1, 1, b - 1, c - 1) << '\n';
		}
	}
}