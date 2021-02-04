#include <iostream>
using namespace std;

int main(void)
{
	int N;
	int decomposition = 0;
	cin >> N;
	for (int i = 0; i < 1000000; i++)
	{
		decomposition = i;
		int num = i;
		while (num > 0)
		{
			decomposition += num % 10;
			num /= 10;
		}
		if (decomposition == N)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << "0" << endl;
}