#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main(void)
{
	int N;
	int x, y;
	vector<pair<int, int>> location;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		location.push_back(make_pair(x, y));
	}
	sort(location.begin(), location.end());
	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", location[i].first, location[i].second);
	}
}