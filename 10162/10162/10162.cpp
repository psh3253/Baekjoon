#include <iostream>
using namespace std;

int main(void)
{
	int a = 0, b = 0, c = 0;
	int T;
	cin >> T;
	if(T / 300 > 0)
	{
		a += T / 300;
		T %= 300;
	}
	if (T / 60 > 0)
	{
		b += T / 60;
		T %= 60;
	}
	if (T / 10 > 0)
	{
		c += T / 10;
		T %= 10;
	}
	if (T == 0)
		cout << a << " " << b << " " << c << '\n';
	else
		cout << -1 << '\n';
}