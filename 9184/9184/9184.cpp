#include <iostream>
using namespace std;
int dp[101][101][101];

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) {
		return dp[a + 50][b + 50][c + 50] = 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		if (dp[a + 50][b + 50][c + 50])
			return dp[a + 50][b + 50][c + 50];
		return dp[a + 50][b + 50][c + 50] = w(20, 20, 20);
	}
	else if (a < b && b < c)
	{
		if (dp[a + 50][b + 50][c + 50])
			return dp[a + 50][b + 50][c + 50];
		return dp[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
	{
		if (dp[a + 50][b + 50][c + 50])
			return dp[a + 50][b + 50][c + 50];
		return dp[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main(void)
{
	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		w(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[a + 50][b + 50][c + 50] << "\n";
	}
}