#include <iostream>
using namespace std;
long long memo[91];

int main(void)
{
	int N;
	cin >> N;
	memo[1] = 1;
	memo[2] = 1;
	for(int i = 3; i < N + 1; i++)
	{
		memo[i] = memo[i - 1] + memo[i - 2];
	}
	cout << memo[N] << '\n';
}