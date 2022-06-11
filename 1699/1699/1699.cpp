#include <iostream>
using namespace std;
int memo[100001];

int main(void)
{
	int n;
	cin >> n;
	for(int i = 1; i < n + 1; i++)
	{
		memo[i] = 987654321;
	}
	for(int i = 1; i < n + 1; i++)
	{
		for(int j = 1; j * j < i + 1; j++)
		{
			memo[i] = min(memo[i], memo[i - j * j] + 1);
		}
	}
	cout << memo[n] << '\n';
}