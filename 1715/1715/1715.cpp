#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int answer = 0;
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < N; i++)
	{
		int card;
		cin >> card;
		pq.push(card);
	}
	while(!pq.empty())
	{
		int x = pq.top();
		pq.pop();
		if (pq.empty())
			break;
		int y = pq.top();
		pq.pop();
		answer += x;
		answer += y;
		pq.push(x + y);
	}
	cout << answer << '\n';
}