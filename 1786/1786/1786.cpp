#include <iostream>
#include <string>
#include <vector>
using namespace std;
int next_position[1000001];
vector<int> pattern_start_position;

void kmp_preprocess(string pattern)
{
	next_position[0] = -1;
	int i = 0;
	int j = -1;
	while (i < pattern.size())
	{
		while (j >= 0 && pattern[i] != pattern[j])
			j = next_position[j];
		i++;
		j++;
		next_position[i] = j;
	}
}

void kmp_search(string text, string pattern)
{
	int i = 0, j = 0;
	while (i < text.size())
	{
		while (j >= 0 && text[i] != pattern[j])
			j = next_position[j];
		if (j == pattern.size() - 1)
		{
			pattern_start_position.push_back(i - j);
			j = next_position[j];
		}
		else
		{
			i++;
			j++;
		}
	}
}

int main(void)
{
	string text, pattern;
	getline(cin, text);
	getline(cin, pattern);
	kmp_preprocess(pattern);
	kmp_search(text, pattern);
	cout << pattern_start_position.size() << '\n';
	for (int i = 0; i < pattern_start_position.size(); i++)
	{
		cout << pattern_start_position[i] + 1 << " ";
	}
	cout << '\n';
}