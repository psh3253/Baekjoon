#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int alphabet_count;
	string s;
	cin >> s;
	alphabet_count = s.length();
	for (int i = 0; i < s.length(); i++)
	{
		if (i + 1 < s.length() && s.at(i) == 'c')
		{
			if (s.at(i + 1) == '=' || s.at(i + 1) == '-')
				alphabet_count--;
		}
		else if (i + 1 < s.length() && s.at(i) == 'd')
		{
			if (s.at(i + 1) == 'z' && i + 2 < s.length())
			{
				if (s.at(i + 2) == '=')
					alphabet_count--;
			}
			else if (s.at(i + 1) == '-')
				alphabet_count--;
		}
		else if (i + 1 < s.length() && s.at(i) == 'l' && s.at(i + 1) == 'j')
			alphabet_count--;
		else if (i + 1 < s.length() && s.at(i) == 'n' && s.at(i + 1) == 'j')
			alphabet_count--;
		else if (i + 1 < s.length() && s.at(i) == 's' && s.at(i + 1) == '=')
			alphabet_count--;
		else if (i + 1 < s.length() && s.at(i) == 'z' && s.at(i + 1) == '=')
			alphabet_count--;
	}
	cout << alphabet_count << endl;
}