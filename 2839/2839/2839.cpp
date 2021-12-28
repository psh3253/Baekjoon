#include <iostream>
using namespace std;

int main(void)
{
	int N;
	int three_count = 0, five_count = 0;
	cin >> N;
	five_count += N / 5;
	N = N % 5;
	three_count += N / 3;
	N = N % 3;
	if (five_count > 0 && N == 1)
	{
		cout << three_count + five_count + 1 << '\n';
	}
	else if(five_count >= 2 && N == 2)
	{
		cout << three_count + five_count + 2 << '\n';
	}
	else if (N == 0)
	{
		cout << three_count + five_count << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}
}
