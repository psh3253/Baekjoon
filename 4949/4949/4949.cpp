#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	stack<char> s;
	char str[100], temp;
	temp = ' ';
	while (temp!= '.')
	{
		cin >> temp;
		if (temp == '(')
		{
			s.push(temp);
		}
		else if (temp == '[')
		{
			s.push(temp);
		}
		else if (temp == ')')
		{
			if (s.top() != '(')
			{
				cout << "no" << endl;
				return 0;
			}
			s.pop();
		}
		else if (temp == ']')
		{
			if (s.top() != '[')
			{
				cout << "no" << endl;
				return 0;
			}
			s.pop();
		}
	}
	if (!s.empty())
	{
		cout << "no" << endl;
	}
	else
	{
		cout << "yes" << endl;
	}
}