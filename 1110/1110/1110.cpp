#include <iostream>
using namespace std;

int main(void)
{
	int answer = 0;
	int N;
	cin >> N;
	int temp = N;
	do
	{
		int a = temp / 10;
		int b = temp % 10;
		temp = b * 10 + (a + b) % 10;
		answer++;
	}
	while (temp != N);
	cout << answer << '\n';
}