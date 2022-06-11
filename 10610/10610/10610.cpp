#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int sum = 0;
	string s;
	vector<int> N;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		N.push_back(s.at(i) - '0');
		sum += s.at(i) - '0';
	}
	if (sum % 3 == 0)
	{
		sort(N.begin(), N.end(), greater<>());
		if (N[s.length() - 1] == 0)
		{
			for (int i = 0; i < s.length(); i++)
			{
				cout << N[i];
			}
			cout << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}
	else
	{
		cout << -1 << '\n';
	}
}