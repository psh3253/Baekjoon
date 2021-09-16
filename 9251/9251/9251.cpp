#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][1001];

int main(void)
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	for (int i = 1; i < s1.length() + 1; i++)
	{
		for (int j = 1; j < s2.length() + 1; j++)
		{
			if (s1.at(i - 1) == s2.at(j - 1)) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	cout << dp[s1.length()][s2.length()] << "\n";
}