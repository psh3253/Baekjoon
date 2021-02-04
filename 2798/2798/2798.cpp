#include <iostream>
using namespace std;

int main(void)
{
	int N, M;
	int card[100];
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> card[i];
	}
	int sum = card[0] + card[1] + card[2];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (i == j || i == k || j == k)
					continue;
				int temp = card[i] + card[j] + card[k];
				if (temp > M)
					continue;
				if (abs(M - sum) > abs(M - temp))
					sum = temp;
			}
		}
	}
	cout << sum << endl;
}