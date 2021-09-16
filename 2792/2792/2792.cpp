#include <iostream>
#include <algorithm>
using namespace std;
int gem[300001];

int main(void)
{
	int child_count, min_jealousy;
	int low = 1, mid, high = 1;
	int	N, M;
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		cin >> gem[i];
		if(gem[i] > high)
		{
			high = gem[i];
		}
	}
	min_jealousy = high;
	while(low <= high)
	{
		child_count = 0;
		mid = (low + high) / 2;
		for(int i = 0; i < M; i++)
		{
			child_count += gem[i] / mid;
			if (gem[i] % mid != 0)
				child_count++;
		}
		if(child_count <= N)
		{
			if (mid < min_jealousy)
				min_jealousy = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout << min_jealousy << '\n';
}