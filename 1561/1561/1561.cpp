#include <iostream>
using namespace std;
int running_time[10000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int answer;
	long long min_final_time = 0;
	long long min_board_count;
	long long N, M;
	long long left = 0, right = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> running_time[i];
		right = max(right, N * running_time[i]);
	}
	if (N <= M)
	{
		cout << N << '\n';
		return 0;
	}
	min_board_count = right;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long board_count = 0;
		for (int i = 0; i < M; i++)
		{
			board_count += mid / running_time[i] + 1;
			if (board_count >= N)
				break;
		}
		if (board_count < N)
		{
			left = mid + 1;
		}
		else
		{
			if (mid < min_board_count)
				min_final_time = mid;
			right = mid - 1;
		}
	}
	for (int i = 0; i < M; i++)
	{
		N -= (min_final_time - 1) / running_time[i] + 1;
	}

	for (int i = 0; i < M; i++)
	{
		if (min_final_time % running_time[i] == 0)
		{
			N--;
			if (N == 0)
			{
				answer = i + 1;
				break;
			}
		}
	}

	cout << answer << '\n';
}