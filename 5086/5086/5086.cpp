#include <iostream>
using namespace std;

int main(void)
{
	int number1, number2;
	while(true)
	{
		cin >> number1 >> number2;
		if (number1 == 0 && number2 == 0)
			break;
		if (number2 % number1 == 0)
			cout << "factor" << endl;
		else if (number1 % number2 == 0)
			cout << "multiple" << endl;
		else
			cout << "neither" << endl;
	}
}