#include <iostream>
using namespace std;
int road[100000];
int cost[100000];

long long getMin(int N)
{
	long long result = 0;
	int minCost = 1000000000;
	for (int i = 0; i < N - 1; i++)
	{
		minCost = min(minCost, cost[i]);
		result += (long long)road[i] * minCost;
	}
	return result;
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> road[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> cost[i];
	}
	cout << getMin(N) << endl;
}