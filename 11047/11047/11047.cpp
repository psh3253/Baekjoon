#include <iostream>
using namespace std;

int value[10];

int getMin(int N, int K)
{
	int coinCount = 0;
	while (K > 0)
	{
		for (int i = N - 1; i >= 0; i--)
		{
			if (K >= value[i]) {
				K -= value[i];
				coinCount++;
				break;
			}
		}
	}
	return coinCount;
}

int main(void)
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> value[i];
	}
	cout << getMin(N, K) << endl;
}