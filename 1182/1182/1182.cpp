#include <iostream>
using namespace std;
int N, S;
int sequence[21];
int answer = 0;
int sum = 0;

void backtracking(int n)
{
	if (n == N)
	{
		if (sum == S)
			answer++;
		return;
	}
	sum += sequence[n];
	backtracking(n + 1);
	sum -= sequence[n];
	backtracking(n + 1);
}

int main(void)
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> sequence[i];
	}
	if (S == 0)
		answer = -1;
	backtracking(0);
	cout << answer << '\n';
}