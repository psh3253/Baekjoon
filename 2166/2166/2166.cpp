#include <iostream>
#include <utility>
using namespace std;

pair<int, int> dot[10001];

int main(void)
{
	int N;
	long long sum1 = 0, sum2 = 0;
	long double result = 0;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		int x, y;
		cin >> x >> y;
		dot[i] = make_pair(x, y);
	}
	dot[N] = dot[0];
	for(int i=0; i<N; i++)
	{
		sum1 += static_cast<long long>(dot[i].first) * static_cast<long long>(dot[i + 1].second);
	}
	for (int i = 0; i < N; i++)
	{
		sum2 += static_cast<long long>(dot[i].second) * static_cast<long long>(dot[i + 1].first);
	}
	result = (sum1 - sum2) / 2.0;
	if (result < 0)
		result = -result;
	printf("%.1Lf", result);
}