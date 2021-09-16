#include <iostream>
#include <algorithm>
using namespace std;
int bottom[100001];
int top[100001];

int main(void)
{
	int low = 0, mid, high;
	int min_count, section_count = 0;
	int top_count, bottom_count;
	int N, H;
	cin >> N >> H;
	for (int i = 0; i < N; i++)
	{
		if(i % 2)
		{
			cin >> top[i / 2];
		}
		else
		{
			cin >> bottom[i / 2];
		}
	}
	min_count = N;
	sort(top, top + N / 2);
	sort(bottom, bottom + N / 2);
	for(int i = 1; i < H + 1; i++)
	{
		bottom_count = N / 2 - (lower_bound(bottom, bottom + N / 2, i) - bottom);
		top_count = N / 2 - (lower_bound(top, top + N / 2, H - i + 1) - top);
		if (bottom_count + top_count == min_count)
			section_count++;
		if (bottom_count + top_count < min_count) {
			min_count = bottom_count + top_count;
			section_count = 1;
		}
	}
	cout << min_count << " " << section_count << '\n';
}