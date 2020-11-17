#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	long long min, max, i, count;
	long double square;
	cin >> min >> max;
	count = 0;
	for (i = min; i < max + 1; i++)
	{
		square = sqrt(i);
		if (i != (long long)square * (long long)square)
		{
			count++;
		}
	}
	cout << count << endl;
}