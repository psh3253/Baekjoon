#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> movePath;

void hanoi(int N, int from, int by, int to)
{
	if (N == 1)
	{
		movePath.push_back(make_pair(from, to));
	}
	else
	{
		hanoi(N - 1, from, to, by);
		movePath.push_back(make_pair(from, to));
		hanoi(N - 1, by, from, to);
	}
}

int main(void)
{
	int N;
	cin >> N;
	hanoi(N, 1, 2, 3);
	cout << movePath.size() << endl;
	for (int i = 0; i < movePath.size(); i++)
	{
		printf("%d %d\n", movePath[i].first, movePath[i].second);
	}
}