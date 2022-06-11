#include <iostream>
using namespace std;
int lesson[100000];

int main(void)
{
	int answer = 987654321;
	int N, M;
	int left = 0, right = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> lesson[i];
		left = max(left, lesson[i]);
		right += lesson[i];
	}
	while(left <= right)
	{
		int disk_count = 1;
		int mid = (left + right) / 2;
		int sum = 0;
		for(int i = 0; i < N; i++)
		{
			if(sum + lesson[i] <= mid)
			{
				sum += lesson[i];
;			}
			else
			{
				sum = lesson[i];
				disk_count++;
			}
		}
		if(disk_count <= M)
		{
			right = mid - 1;
			answer = min(answer, mid);
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << answer << '\n';
}