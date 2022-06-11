#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> bag;
vector<pair<int, int>> jewelry;
priority_queue<int> pq;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long answer = 0;
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int M, V;
		cin >> M >> V;
		jewelry.push_back(make_pair(M, V));
	}
	for (int i = 0; i < K; i++)
	{
		int C;
		cin >> C;
		bag.push_back(C);
	}
	sort(jewelry.begin(), jewelry.end());
	sort(bag.begin(), bag.end());
	int idx = 0;
	for (int i = 0; i < bag.size(); i++)
	{
		while (idx < N && jewelry[idx].first <= bag[i])
		{
			pq.push(jewelry[idx++].second);
		}
		if(!pq.empty())
		{
			answer += pq.top();
			pq.pop();
		}
	}
	cout << answer << '\n';
}