#include <algorithm>
#include <iostream>
using namespace std;
long long pos[200001];

int main(void)
{
	long long current_distance = 0;
	int modem_count = 0;
	long long max_modem_distance = 1;
	long long low = 0, mid, high = 1;
	int N, C;
	cin >> N >> C;
	for(int i = 0; i < N; i++)
	{
		cin >> pos[i];
		if (pos[i] > high)
			high = pos[i];
	}
	sort(pos, pos + N);
	while(low <= high)
	{
		modem_count = 0;
		current_distance = 0;
		mid = (low + high) / 2;
		for(int i = 0; i < N - 1; i++)
		{
			current_distance += pos[i + 1] - pos[i];
			if (current_distance >= mid)
			{
				modem_count++;
				current_distance = 0;
			}
		}
		modem_count++;
		if(modem_count < C)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
			if (mid > max_modem_distance)
				max_modem_distance = mid;
		}
	}
	cout << max_modem_distance << '\n';
}