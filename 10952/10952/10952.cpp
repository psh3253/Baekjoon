#include <iostream>
using namespace std;

int main(void)
{
	while(true)
	{
		int a, b;
		cin >> a >> b;
		if (a == b && a == 0)
			break;
		cout << a + b << '\n';
	}
}