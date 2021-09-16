#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool mod = false;;
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;
	int N, num;
	cin >> N;
	for(int i  = 0; i < N; i++)
	{
		cin >> num;
		if(mod)
		{
			if(!pq1.empty() && pq1.size() == pq2.size() + 1 && num < pq1.top())
			{
				pq2.push(pq1.top());
				pq1.pop();
				pq1.push(num);
			}
			else
			{
				pq2.push(num);
			}
		}
		else
		{
			if(!pq2.empty() && pq1.size() == pq2.size() && num > pq2.top())
			{
				pq1.push(pq2.top());
				pq2.pop();
				pq2.push(num);
			}
			else
			{
				pq1.push(num);
			}
		}
		mod = !mod;
		cout << pq1.top() << '\n';
	}
}