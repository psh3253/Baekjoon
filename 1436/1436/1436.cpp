#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int N;
	int number = 0;
	cin >> N;
	for (int i = 666; i < 10000000; i++)
	{
		if (to_string(i).find("666") != string::npos)
			number++;
		if(number == N)
		{
			cout << i << endl;
			break;
		}
	}
}