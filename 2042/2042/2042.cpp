#include <iostream>
#include <vector>
using namespace std;
int N, M, K;

long long arr[1000000];
long long tree[4000000];

long long init(int start, int end, int node)
{
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long num)
{
	if (index < start || index > end)
		return;
	tree[node] -= arr[index];
	tree[node] += num;
	if (start == end)
	{
		arr[index] = num;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, num);
	update(mid + 1, end, node * 2 + 1, index, num);
}

int main(void)
{
	vector<long long> answer;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	init(0, N - 1, 1);
	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(0, N - 1, 1, (int)b - 1, c);
		}
		else
		{
			answer.push_back(sum(0, N - 1, 1, (int)b - 1, (int)c - 1));
		}
	}
	for(int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << '\n';
	}
}