#include <iostream>
#include <string>
using namespace std;

int getMIn(string expression)
{
	int number = 0;
	bool minus = false;
	string temp = "";
	for (int i = 0; i <= expression.length(); i++)
	{
		if (expression[i] == '-' || expression[i] == '+' || expression[i] == '\0')
		{
			if (minus)
			{
				number -= stoi(temp);
			}
			else
			{
				number += stoi(temp);
			}
			if (expression[i] == '-')
			{
				minus = true;
			}
			temp = "";
		}
		else
		{
			temp += expression[i];
		}
	}
	return number;
}

int main(void)
{
	string expression;
	cin >> expression;
	cout << getMIn(expression) << endl;
}