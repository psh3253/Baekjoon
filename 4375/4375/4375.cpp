#include <iostream>
using namespace std;

int main(void)
{
	int n;
	while (cin >> n)
	{
		int number = 1;
		int digit = 1;
		while (true)
		{
			if (number % n == 0)
				break;
			number = (number * 10 + 1) % n;
			digit++;
		}
		cout << digit << endl;
	}
}