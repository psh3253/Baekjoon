#include <iostream>
using namespace std;
int k;
int S[13];
int sequence[7] = {0, };

void backtracking(int n)
{
	if (n == 7)
	{
		for(int i = 1; i < 7; i++)
		{
			cout << sequence[i] << " ";
		}
		cout << '\n';
		return;
	}
	for(int i = 1; i < k + 1; i++)
	{
		if(sequence[n-1] < S[i])
		{
			sequence[n] = S[i];
			backtracking(n + 1);
		} 
	}
}

int main(void)
{
	while(true)
	{
		cin >> k;
		if(k == 0)
			break;
		for(int i = 1; i < k + 1; i++)
		{
			cin >> S[i];
		}
		backtracking(1);
		cout << '\n';
	}
}