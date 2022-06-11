#include <iostream>
using namespace std;
int fail[1000001];

void kmp_preprocessing(string pattern)
{
	fail[0] = -1;
	int i = 0, j = -1;
	int size = pattern.size();
	while(i < size)
	{
		while (j >= 0 && pattern[i] != pattern[j])
			j = fail[j];
		i++;
		j++;
		fail[i] = j;
	}
}

int main(void)
{
	kmp_preprocessing("aabaaa");
	while(true)
	{
		int answer = 0;
		string s;
		cin >> s;
		if(s == ".")
		{
			break;
		}
		fill_n(fail, s.size() + 1, 0);
		kmp_preprocessing(s);
		int size = s.size();
		if (size % (size - fail[size]) == 0)
			answer = size / (size - fail[size]);
		else
			answer = 1;
		cout << answer << '\n';
	}
}