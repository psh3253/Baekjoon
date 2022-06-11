#include <algorithm>
#include <iostream>
using namespace std;
int card[500000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> card[i];
	}
	sort(card, card + N);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		bool is_search = false;
		int number;
		cin >> number;
		int left = 0;
		int right = N - 1;
		while(left <= right)
		{
			int mid = (left + right) / 2;
			if(number < card[mid])
			{
				right = mid - 1;
			}
			else if(number > card[mid])
			{
				left = mid + 1;
			}
			else
			{
				is_search = true;
				cout << 1 << " ";
				break;
			}
		}
		if(!is_search)
			cout << 0 << " ";
	}
	cout << "\n";
}
