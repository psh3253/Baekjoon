#include <iostream>
using namespace std;

int main(void)
{
	int max = 0, max_count = 0;
	char c, max_alphabet;
	int alphabet[26] = { 0, };
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		c = s.at(i);
		if (c >= 'a' && c <= 'z')
			alphabet[c - 'a']++;
		else if (c >= 'A' && c <= 'Z')
			alphabet[c - 'A']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] > max)
		{
			max = alphabet[i];
			max_alphabet = i + 'A';
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] == max)
			max_count++;
	}
	if (max_count >= 2)
		cout << '?' << endl;
	else
		cout << max_alphabet << endl;
}