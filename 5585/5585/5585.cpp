#include <iostream>
using namespace std;

int main(void)
{
	int answer = 0;
	int n;
	cin >> n;
	n = 1000 - n;
	if(n / 500 > 0)
	{
		answer += n / 500;
		n %= 500;
	}
	if (n / 100 > 0)
	{
		answer += n / 100;
		n %= 100;
	}
	if (n / 50 > 0)
	{
		answer += n / 50;
		n %= 50;
	}
	if (n / 10 > 0)
	{
		answer += n / 10;
		n %= 10;
	}
	if (n / 5 > 0)
	{
		answer += n / 5;
		n %= 5;
	}
	answer += n;
	cout << answer << '\n';
}