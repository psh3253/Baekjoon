#include <iostream>
using namespace std;

int main(void)
{
	int answer = 1;
	long long sum = 0;
	long long S;
	cin >> S;
	while(sum <= S)
	{
		sum += answer;
		answer++;
	}
	cout << answer - 2 << '\n';
}