#include <iostream>
using namespace std;

int main(void)
{
	bool alphabet[26] = { false, };
	string s;
	int N, group_word_count;
	cin >> N;
	group_word_count = N;
	for (int i = 0; i < N; i++)
	{
		fill_n(alphabet, 26, false);
		cin >> s;
		for (int j = 1; j < s.length(); j++)
		{
			if (alphabet[s.at(j) - 'a'])
			{
				group_word_count--;
				break;
			}
			if (s.at(j - 1) != s.at(j))
				alphabet[s.at(j - 1) - 'a'] = true;
		}
	}
	cout << group_word_count << endl;
}