#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> meeting[100000];

int getMax(int N)
{
	int meetingCount = 0;
	int last = 0;
	for (int i = 0; i < N; i++)
	{
		if (meeting[i].second >= last)
		{
			last = meeting[i].first;
			meetingCount++;
		}
	}
	return meetingCount;
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> meeting[i].second >> meeting[i].first;
	}
	sort(meeting, meeting + N);
	cout << getMax(N) << endl;
}