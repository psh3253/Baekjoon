#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int a;
	string S;
	cin >> S;
	for (int i = 'a'; i <= 'z'; i++)
	{
		if ((a = S.find(i)) != string::npos)
			cout << a << " ";
		else
			cout << -1 << " ";
	}
}