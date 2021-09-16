#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	stack<char> st;
	string s;
	int T, result;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		result = 1;
		while (!st.empty())
			st.pop();
		cin >> s;
		for(int j = 0; j < s.size(); j++)
		{
			if(s.at(j) == '(')
			{
				st.push(s.at(j));
			}
			else
			{
				if(st.empty())
				{
					result = 0;
					break;
				}
				else
				{
					st.pop();
				}
			}
		}
		if(result && st.empty())
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}