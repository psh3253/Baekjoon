#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, i, j, sum = 0, temp;
	int* weight;
	cin >> n;
	weight = new int[n];
	for (i = 0; i < n; i++)
	{
		cin >> weight[i];
		sum += weight[i];
	}
	sort(weight, weight + n);
	for (i = 1; i < sum + 1; i++)
	{
		for (j = n - 1, temp = i; temp > 0 && weight[j] <= i; j--)
		{
			if (j == -1)
			{
				cout << i << endl;
				return 0;
			}
			if (temp - weight[j] >= 0)
			{
				temp -= weight[j];
			}
		}
	}
}