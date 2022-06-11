#include <iostream>
using namespace std;
long long memo[91];

int main(void)
{
	int n;
	cin >> n;
	memo[0] = 0;
	memo[1] = 1;
	for (int i = 2; i < n + 1; i++)
		memo[i] = memo[i - 1] + memo[i - 2];
	cout << memo[n] << '\n';
}