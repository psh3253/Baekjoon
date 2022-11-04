#include <iostream>
using namespace std;
int alpha[26];

int main(void)
{
	string answer;
	string name;
	cin >> name;
	for (int i = 0; i < name.size(); i++)
	{
		alpha[name[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < alpha[i] / 2; j++)
		{
			answer += i + 'A';
		}
		alpha[i] = alpha[i] % 2;
	}
	int c = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] == 1)
		{
			c++;
			answer += i + 'A';
			alpha[i] = 0;
		}
	}
	if (c > 1)
	{
		cout << "I'm Sorry Hansoo" << '\n';
		return 0;
	}
	else if (c == 1)
	{
		for (int i = answer.size() - 2; i >= 0; i--)
			answer += answer[i];
	}
	else
	{
		for (int i =  answer.size() - 1; i >= 0; i--)
			answer += answer[i];
	}
	cout << answer << '\n';
}