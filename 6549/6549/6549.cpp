#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long height[100001];
long long tree[1000000];

void init(int start, int end, int node)
{
	if (start == end)
		tree[node] = start;
	else
	{
		int mid = (start + end) / 2;
		init(start, mid, node * 2);
		init(mid + 1, end, node * 2 + 1);
		if (height[tree[node * 2]] < height[tree[node * 2 + 1]])
			tree[node] = tree[node * 2];
		else
			tree[node] = tree[node * 2 + 1];
	}
}

int getMinIndex(int start, int end, int node, int left, int right)
{
	if (end < left || start > right)
		return -1;
	else if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	int leftMinIndex = getMinIndex(start, mid, node * 2, left, right);
	int rightMinIndex = getMinIndex(mid + 1, end, node * 2 + 1, left, right);

	if (leftMinIndex == -1)
		return rightMinIndex;
	else if (rightMinIndex == -1)
		return leftMinIndex;
	else if (height[leftMinIndex] < height[rightMinIndex])
		return leftMinIndex;
	else
		return rightMinIndex;
}

long long getMaxArea(int start, int end)
{
	int index = getMinIndex(0, n - 1, 1, start, end);
	long long area = (end - start + 1) * height[index];

	if(start < index)
	{
		long long temp = getMaxArea(start, index - 1);
		area = max(area, temp);
	}

	if(index < end)
	{
		long long temp = getMaxArea(index + 1, end);
		area = max(area, temp);
	}
	return area;
}

int main(void)
{
	while (true)
	{
		long long max_area = 0;
		cin >> n;
		if (n == 0)
			break;
		for(int i = 0; i < n; i++)
		{
			cin >> height[i];
		}
		init(0, n - 1, 1);
		max_area = getMaxArea(0, n - 1);
		cout << max_area << '\n';
	}
}