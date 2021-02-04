#include <iostream>
using namespace std;

int main(void)
{
	int N;
	long long g = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		g += (N / i) * i;
	}
	cout << g << endl;
}