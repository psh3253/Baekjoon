#include <algorithm>
#include <iostream>
using namespace std;
int local[10000];

int main(void)
{
	int answer = 0;
	int min_cost = 0;
	int max_cost = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> local[i];
		max_cost = max(max_cost, local[i]);
	}
	sort(local, local + N);
	int M;
	cin >> M;

	while (min_cost <= max_cost)
	{
		int mid = (min_cost + max_cost) / 2;
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += min(mid, local[i]);
		}
		if (sum <= M)
		{
			min_cost = mid + 1;
			answer = mid;
		}
		else
		{
			max_cost = mid - 1;
		}
	}
	cout << answer << '\n';
}