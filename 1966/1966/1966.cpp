#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main(void)
{
	queue<pair<int, int>> q;
	priority_queue<int> pq;
	int T, N, M;
	int importance, index, order;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		while (!q.empty())
			q.pop();
		while (!pq.empty())
			pq.pop();
		order = 1;
		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			cin >> importance;
			pq.push(importance);
			q.push(make_pair(importance, j));
		}
		while (!q.empty())
		{
			importance = q.front().first;
			index = q.front().second;
			q.pop();
			if(pq.top() == importance)
			{
				pq.pop();
				if (index == M)
				{
					cout << order << '\n';
					break;
				}
				order++;
			}
			else
			{
				q.push(make_pair(importance, index));
			}
		}
	}
}