#include <iostream>
using namespace std;

void star(int N)
{
	if (N == 1)
	{
		cout << "*" << endl;
		return;
	}
	else
	{
		star(N / 3); star(N / 3); star(N / 3);
		cout << endl;
		star(N / 3);
		star(N / 3);
		cout << endl;
		star(N / 3); star(N / 3); star(N / 3);
		cout << endl;
	}

}

int main(void)
{
	star(27);
}