#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void)
{
	int answer = 0;
	vector<pair<int, int>> class_v;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int S, T;
		cin >> S >> T;
		class_v.push_back({ S, T });
	}
	sort(class_v.begin(), class_v.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(class_v[0].second);
	for (int i = 1; i < class_v.size(); i++)
	{
		if (class_v[i].first < pq.top())
		{
			pq.push(class_v[i].second);
		}
		else
		{
			pq.pop();
			pq.push(class_v[i].second);
		}
	}
	answer = pq.size();
	cout << answer << '\n';
}