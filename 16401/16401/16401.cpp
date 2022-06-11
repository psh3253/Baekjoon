#include <iostream>
using namespace std;
int snack[1000000];

int main(void)
{
	int answer = 0;
	int M, N;
	int left = 1, right = 0;
	cin >> M >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> snack[i];
		right = max(right, snack[i]);
	}
	while(left <= right)
	{
		int snack_count = 0;
		int mid = (left + right) / 2;
		for(int i = 0; i < N; i++)
		{
			snack_count += snack[i] / mid;
		}
		if(snack_count < M)
		{
			right = mid - 1;
		}
		else
		{
			answer = max(answer, mid);
			left = mid + 1;
		}
	}
	cout << answer << '\n';
}