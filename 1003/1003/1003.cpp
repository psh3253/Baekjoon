#include <iostream>
#include <utility>
using namespace std;
int c0, c1;
int dp[41];
pair<int, int> c[41];

pair<int, int> fibonacci(int n) {
	if (n == 0) {
		return c[0] = make_pair(1, 0);
	}
	else if (n == 1) {
		return c[1] = make_pair(0, 1);
	}
	else {
		if (c[n].first != 0 && c[n].second != 0)
			return c[n];
		else
		{
			return c[n] = make_pair(fibonacci(n - 1).first + fibonacci(n - 2).first, fibonacci(n - 1).second + fibonacci(n - 2).second);
		}

	}
}

int main(void)
{
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		c0 = 0;
		c1 = 0;
		cin >> n;
		fibonacci(n);
		printf("%d %d\n", c[n].first, c[n].second);
	}
	return 0;
}