#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int n, i, j;
	bool success;
	string str;
	stack<char> s;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		success = 1;
		cin >> str;
		for (j = 0; j < str.length(); j++)
		{
			if (str[j] == '(')
				s.push('(');
			else if (str[j] == ')')
			{
				if (s.empty())
				{
					success = false;
					cout << "NO" << endl;
					break;
				}
				else
				{
					s.pop();
				}
			}
		}
		if (!s.empty())
		{
			cout << "NO" << endl;
		}
		else if(success == true)
		{
			cout << "YES" << endl;
		}
		while (!s.empty()) s.pop();
	}
	return 0;
}