#include <iostream>
using namespace std;
int memo[31][31];

int main(void)
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int N, M;
		cin >> N >> M;
		for (int j = 0; j < N + 1; j++)
			fill_n(memo[j], M + 1, 1);
		for(int j = 1 ; j < N + 1; j++)
		{
			for(int k = 1; k < M + 1; k++)
			{
				if(j != k)
				{
					memo[j][k] = memo[j - 1][k - 1] + memo[j][k - 1];
				}
			}
		}
		cout << memo[N][M] << '\n';
	}
}