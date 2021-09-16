#include <algorithm>
#include <iostream>
using namespace std;

int withdrawTime[1000];

int getMIn(int N)
{
	int result = 0;
	sort(withdrawTime, withdrawTime + N);
	for (int i = 0; i < N; i++)
	{
		result += withdrawTime[i] * (N - i);
	}
	return result;
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> withdrawTime[i];
	}
	cout << getMIn(N) << endl;
}