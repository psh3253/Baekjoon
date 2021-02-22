#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(string s1, string s2)
{
	if (s1.length() != s2.length())
		return s1.length() < s2.length();
	else
		return s1 < s2;
}

int main(void)
{
	int N;
	vector<string> words;
	string word;
	string prev = "";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> word;
		words.push_back(word);
	}
	sort(words.begin(), words.end(), compare);
	for (int i = 0; i < N; i++)
	{
		if (words[i] != prev)
		{
			prev = words[i];
			cout << words[i] << endl;
		}
	}
}