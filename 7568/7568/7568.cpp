#include <iostream>
using namespace std;

int main(void)
{
	int N;
	int weight, height;
	pair<int, int> bulk[50];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> weight >> height;
		bulk[i] = make_pair(weight, height);
	}
	for (int i = 0; i < N; i++)
	{
		int rank = 1;
		for (int j = 0; j < N; j++)
		{
			if (bulk[i].first < bulk[j].first && bulk[i].second < bulk[j].second)
			{
				rank++;
			}
		}
		cout << rank << " ";
	}
}