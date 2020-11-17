#include <iostream>
using namespace std;
int parent[1000001];

int getParent(int x)
{
	if (parent[x] == x)
		return x;
	else
		return getParent(parent[x]);
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
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0)
		{
			unionParent(b, c);
		}
		else if (a == 1)
		{
			if (equalParent(b, c))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}