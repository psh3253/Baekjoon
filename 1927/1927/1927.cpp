#include <iostream>
#include <queue>
using namespace std;
priority_queue< int, vector<int>, greater<int> > pq;

int main(void)
{
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x == 0)
		{
			if (pq.empty())
				printf("0\n");
			else
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}
	}
	return 0;
}