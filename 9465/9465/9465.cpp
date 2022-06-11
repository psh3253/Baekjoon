#include <iostream>
#include <algorithm>
using namespace std;
int sticker[3][100001];
int memo[3][100001];

int main(void)
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		for(int j = 1; j < 3; j++)
		{
			fill_n(memo[j], n + 1, 0);
			for(int k = 1; k < n + 1; k++)
			{
				cin >> sticker[j][k];
			}
		}
		for(int j = 1; j < n + 1; j++)
		{
			for(int k = 1; k < 3; k++)
			{
				if(k == 1)
				{
					memo[k][j] = max(memo[k][j - 1], memo[k + 1][j - 1] + sticker[k][j]);
					if (j >= 2)
						memo[k][j] = max(memo[k][j], memo[k + 1][j - 2]);
				}
				else
				{
					memo[k][j] = max(memo[k][j - 1], memo[k - 1][j - 1] + sticker[k][j]);
					if (j >= 2)
						memo[k][j] = max(memo[k][j], memo[k - 1][j - 2]);
				}
			}
		}
		cout << max(memo[1][n], memo[2][n]) << '\n';
	}
}