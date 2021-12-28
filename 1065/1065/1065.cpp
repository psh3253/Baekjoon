#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int N;
	int sum = 0;
	cin >> N;
	for(int i = 1; i < N + 1; i++)
	{
		bool is_han_su = true;
		string s = std::to_string(i);
		if(s.length() == 1 || s.length() == 2)
		{
			sum++;
			continue;
		}
		int d = s.at(1) - s.at(0);
		for(int j = 1; j < s.length() - 1; j++)
		{
			int dd = s.at(j + 1) - s.at(j);
			if (d != dd) {
				is_han_su = false;
				break;
			}
		}
		if (is_han_su)
			sum++;
	}
	cout << sum << '\n';
}