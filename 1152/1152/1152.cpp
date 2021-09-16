#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int word_count = 1;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) == ' ')
			word_count++;
	}
	if (s.front() == ' ')
		word_count--;
	if (s.back() == ' ')
		word_count--;
	cout << word_count;
}