#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> min_hp;
priority_queue<int, vector<int>, less<int>> max_hp;

int main(void)
{
	int n, x, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if(min_hp.size()  < max_hp.size())
		{
			min_hp.push(x);
		}
		else
		{
			max_hp.push(x);
		}
		if(min_hp.size() != 0 && max_hp.size() != 0)
		{
			if (min_hp.top() < max_hp.top())
			{
				temp = min_hp.top();
				min_hp.pop();
				min_hp.push(max_hp.top());
				max_hp.pop();
				max_hp.push(temp);
			}
		}
		printf("%d\n", max_hp.top());
	}
	return 0;
}