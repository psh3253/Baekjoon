#include <iostream>
using namespace std;

long long square(long long a, long long b, int c)
{
	if(b == 1)
	{
		return a % c;
	}
	if(b % 2)
	{
		return a * square(a, b - 1, c) % c;
	}
	else
	{
		return square(a, b / 2, c) * square(a, b / 2, c) % c;
	}
}

int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;
	cout << square(A, B, C) << '\n';
}