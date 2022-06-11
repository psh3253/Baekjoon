#include <iostream>
using namespace std;
int memo[201][201];

int main(void)
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n + 1; i++)
		memo[1][i] = 1;
	for(int i = 2; i < k + 1; i++)
	{
		for(int j = 0; j < n + 1; j++)
		{
			for(int l = 0; l < j + 1; l++)
			{
				memo[i][j] = (memo[i][j] + memo[i - 1][l]) % 1000000000;
			}
		}
	}
	cout << memo[k][n] << '\n';
}