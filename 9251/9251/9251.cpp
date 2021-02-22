#include <iostream>
using namespace std;

int dp[1001][1001];

int getLCS(string str1, string str2)
{
	for (int i = 1; i < str2.length(); i++)
	{
		for (int j = 1; j < str1.length(); j++)
		{
			if (str2[i] == str1[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[str2.length() - 1][str1.length() - 1];
}
int main(void)
{
	string str1, str2;
	cin >> str1;
	cin >> str2;
	str1 = " " + str1;
	str2 = " " + str2;
	cout << getLCS(str1, str2) << endl;
}