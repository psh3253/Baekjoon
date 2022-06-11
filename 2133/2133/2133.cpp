#include <iostream>
using namespace std;
int memo[31];

int main(void)
{
	int N;
	cin >> N;
	memo[0] = 1;
	memo[2] = 3;
	for(int i = 4; i < N + 1; i += 2)
	{
		memo[i] += 3 * memo[i - 2];
		for(int j = 0; j <= i - 4; j+= 2)
		{
			memo[i] += 2 * memo[j];
		}
	}
	cout << memo[N] << '\n';
}