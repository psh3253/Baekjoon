#include <iostream>
using namespace std;

int fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacci(n - 2) + fibonacci(n - 1);
}

int main(void)
{
	int n;
	cin >> n;
	cout << fibonacci(n) << endl;
}