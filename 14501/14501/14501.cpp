#include <iostream>
using namespace std;
int memo[17];
int t[17];
int p[17];

int main(void)
{
	int N;
	cin >> N;
	for(int i = 1; i < N + 1; i++)
	{
		cin >> t[i] >> p[i];
	}
	for(int i = 1; i < N + 2; i++)
	{
		for(int j = 1; j < i; j++)
		{
			if(i == t[j] + j)
			{
				memo[i] = max(p[j] + memo[j], memo[i]);
			}
			memo[i] = max(memo[i], memo[i - 1]);
		}
	}
	cout << memo[N + 1] << '\n';
}