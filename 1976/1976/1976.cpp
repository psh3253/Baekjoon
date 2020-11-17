#include <iostream>
using namespace std;
int city[201][201];
int parent[201];

int getParent(int x)
{
	if (parent[x] == x)
		return parent[x];
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

bool equalParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b)
		return true;
	else
		return false;
}

int main(void)
{
	int n, m, pre, cur;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &city[i][j]);
			if (city[i][j] == 1)
			{
				unionParent(i, j);
			}
		}
	}
	scanf("%d", &pre);
	for (int i = 0; i < m - 1; i++)
	{
		scanf("%d", &cur);
		if (!equalParent(pre, cur))
		{
			printf("NO\n");
			return 0;
		}
		pre = cur;
	}
	printf("YES\n");
	return 0;
}