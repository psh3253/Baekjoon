#include <iostream>
using namespace std;

int main(void)
{
	int N, number, sum = 0;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		scanf("%1d", &number);
		sum += number;
	}
	cout << sum;
}