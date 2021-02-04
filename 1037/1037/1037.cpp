#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
	int count;
	int factor[50];
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> factor[i];
	}
	sort(factor, factor + count);
	cout << (long long)factor[0] * factor[count - 1] << endl;
}