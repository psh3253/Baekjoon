#include <iostream>
using namespace std;
int memo[100001];

int main(void)
{
	int n, k;
	cin >> n >> k;
	fill_n(memo, 100001, 987654321);
	int temp;
	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		memo[temp] = 1;
	}
	for(int i = 1; i < k + 1; i++)
	{
		for(int j = 1; j <= i - j; j++)
		{
			memo[i] = min(memo[i], memo[j] + memo[i - j]);
		}
	}
	if (memo[k] == 987654321)
		cout << -1 << '\n';
	else
		cout << memo[k] << '\n';
}