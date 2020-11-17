#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	char temp;
	int i, count = 0;
	stack<char> s;
	string str;
	cin >> str;
	for (i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			s.push('(');
		}
		else if(str[i] == ')')
		{
			s.pop();
			if (str[i - 1] == '(')
			{
				count += s.size();
			}
			else
			{
				count += 1;
			}
		}
	}
	cout << count << endl;
	return 0;
}