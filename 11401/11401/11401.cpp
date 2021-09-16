#include <iostream>
using namespace std;

long long square(long long n, int p)
{
	long long temp;
	if (p == 0)
		return 1;
	if(p % 2)
	{
		return n * square(n, p - 1) % 1000000007;
	}
	else
	{ 
		temp = square(n, p / 2);
		return temp * temp % 1000000007;
	}
}

int main(void)
{
	int N, K;
	long long A = 1, B = 1;
	cin >> N >> K;
	for(int i = N - K + 1; i < N + 1; i++)
	{
		A = A * i % 1000000007;
	}
	for(int i = 1; i < K + 1; i++)
	{
		B = B * i % 1000000007;
	}
	cout << A * square(B, 1000000007 - 2) % 1000000007 << '\n';
}