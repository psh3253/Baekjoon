#include <iostream>
#include <algorithm>
using namespace std;
int card[500001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	int target;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> card[i];
	}
	sort(card, card + N);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> target;
		if(binary_search(card, card + N, target))
		{
			cout << upper_bound(card, card + N, target) - lower_bound(card, card + N, target) << ' ';
		}
		else
		{
			cout << 0 << ' ';
		}
	}
	cout << '\n';
}