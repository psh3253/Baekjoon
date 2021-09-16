#include <iostream>
using namespace std;

int gcd(int number1, int number2)
{
	int result = number1 % number2;
	if (result == 0)
		return number2;
	else
		return gcd(number2, result);
}

int main(void)
{
	int number1, number2;
	cin >> number1 >> number2;
	cout << gcd(number1, number2) << endl;
	cout << number1 * number2 / gcd(number1, number2) << endl;
}