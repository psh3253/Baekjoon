#include <iostream>
using namespace std;

int main(void)
{
	int zero_count = 0;;
	int one_count = 0;
	char current;
	string s;
	cin >> s;

	current = s.at(0);
	for(int i = 1; i < s.length(); i++)
	{
		if(current != s.at(i))
		{
			if (s.at(i) == '0')
				zero_count++;
			else
				one_count++;
			current = s.at(i);
		}
	}
	cout << max(zero_count, one_count) << '\n';
}