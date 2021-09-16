#include <iostream>
#include <utility>
using namespace std;

int main(void)
{
	int N, x, y, rank;
	pair<int, int> person[50];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> person[i].first >> person[i].second;
	}
	for (int i = 0; i < N; i++)
	{
		rank = 1;
		for (int j = 0; j < N; j++)
		{
			if (i != j && person[i].first < person[j].first && person[i].second < person[j].second)
				rank++;
		}
		cout << rank << " ";
	}
}