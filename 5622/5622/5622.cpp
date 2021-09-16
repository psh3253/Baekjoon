#include <iostream>
using namespace std;

int main(void)
{
	int time = 0;
	char c;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		c = s.at(i);
		if (c >= 'A' && c <= 'C')
			time += 3;
		else if (c >= 'D' && c <= 'F')
			time += 4;
		else if (c >= 'G' && c <= 'I')
			time += 5;
		else if (c >= 'J' && c <= 'L')
			time += 6;
		else if (c >= 'M' && c <= 'O')
			time += 7;
		else if (c >= 'P' && c <= 'S')
			time += 8;
		else if (c >= 'T' && c <= 'V')
			time += 9;
		else if (c >= 'W' && c <= 'Z')
			time += 10;
	}
	cout << time << endl;
}