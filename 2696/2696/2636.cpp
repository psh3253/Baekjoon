#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	priority_queue<int> max_q;
	priority_queue<int, vector<int>, greater<int>> min_q;
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		while (!max_q.empty())
			max_q.pop();
		while (!min_q.empty())
			min_q.pop();
		int M;
		cin >> M;
		cout << M / 2 + 1 << '\n';
		for(int j = 0; j < M; j++)
		{
			int number;
			cin >> number;
			if(j % 2 == 0)
			{
				max_q.push(number);
				if(!min_q.empty() && max_q.top() > min_q.top())
				{
					int temp = max_q.top();
					int temp1 = min_q.top();
					max_q.pop();
					min_q.pop();
					max_q.push(temp1);
					min_q.push(temp);
				}
				cout << max_q.top() << " ";
			}
			else
			{
				min_q.push(number);
				if (max_q.top() > min_q.top())
				{
					int temp = max_q.top();
					int temp1 = min_q.top();
					max_q.pop();
					min_q.pop();
					max_q.push(temp1);
					min_q.push(temp);
				}
			}
		}
		cout << '\n';
	}
}