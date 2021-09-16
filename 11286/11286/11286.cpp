#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> pq;
	int N, x;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> x;
		if(x == 0)
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				if(pq.top().second)
				{
					cout << pq.top().first << '\n';
				}
				else
				{
					cout << -pq.top().first << '\n';
				}
				pq.pop();
			}
		}
		else
		{
			if(x > 0)
			{
				pq.push(make_pair(x, true));
			}
			else
			{
				pq.push(make_pair(-x, false));
			}
		}
	}
}