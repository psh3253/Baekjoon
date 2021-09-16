#include <iostream>
using namespace std;

int main(void)
{
	int N, M, max_sum = 0, card[100] = { 0, };
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> card[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (i != j && j != k && i != k && card[i] + card[j] + card[k] <= M && card[i] + card[j] + card[k] > max_sum)
					max_sum = card[i] + card[j] + card[k];
			}
		}
	}
	cout << max_sum << endl;
}