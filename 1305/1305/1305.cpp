#include <iostream>
using namespace std;
int fail[10000001];

void kmp_processing(string pattern)
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
	string s;
	int L;
	cin >> L;
	cin >> s;
	kmp_processing(s);
	cout << L - fail[L] << '\n';
}