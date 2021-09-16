#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main(void)
{
	long long result;
	long long temp_count;
	long long low = 1, mid, high;
	long long N, K;
	cin >> N;
	cin >> K;
	high = N * N;
	result = N * N;

	while (low <= high)
	{
		temp_count = 0;
		mid = (low + high) / 2;
		for (int i = 1; i < N + 1; i++)
		{
			temp_count += min(mid / i, N);
		}
		if (temp_count < K)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
			if (mid < result)
				result = mid;
		}
	}
	cout << result << '\n';
}