#include <iostream>
using namespace std;
int memo[12];

int main(void)
{
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 4;
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		for (int j = 4; j < n + 1; j++)
			memo[j] = memo[j - 1] + memo[j - 2] + memo[j - 3];
		cout << memo[n] << '\n';
	}
}