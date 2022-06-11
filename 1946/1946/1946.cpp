#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector<pair<int, int>> worker;
		int N;
		cin >> N;
		int answer = N;
		for (int j = 0; j < N; j++)
		{
			int a, b;
			cin >> a >> b;
			worker.push_back(make_pair(a, b));
		}
		sort(worker.begin(), worker.end());
		int min = N;
		for (int j = 0; j < N; j++)
		{
			if (worker[j].second > min)
			{
				answer--;
			}
			else
			{
				min = worker[j].second;
			}
		}
		cout << answer << '\n';
	}
}