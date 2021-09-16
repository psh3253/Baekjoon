#include <iostream>
using namespace std;

int main(void)
{
	int N, temp, decomposition_sum;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		decomposition_sum = i;
		temp = i;
		while (temp > 0)
		{
			decomposition_sum += temp % 10;
			temp /= 10;
		}
		if (decomposition_sum == N)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
}