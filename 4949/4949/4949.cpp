#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	int result;
	stack<char> st;
	string s;
	while (true)
	{
		result = 1;
		while (!st.empty())
			st.pop();
		getline(cin, s);
		if (s == ".")
			break;
		for (int i = 0; i < s.size(); i++)
		{
			if (s.at(i) == '[')
				st.push('[');
			else if (s.at(i) == '(')
				st.push('(');
			else if (s.at(i) == ')')
			{
				if (st.empty())
				{
					result = 0;
					break;
				}
				else
				{
					if (st.top() == '(')
						st.pop();
					else
					{
						result = 0;
						break;
					}
				}
			}
			else if (s.at(i) == ']')
			{
				if (st.empty())
				{
					result = 0;
				}
				else
				{
					if (st.top() == '[')
						st.pop();
					else
					{
						result = 0;
						break;
					}
				}
			}
		}
		if (result && st.empty())
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}
}