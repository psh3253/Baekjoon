#include <iostream>
#include <cmath>
#define INF 2000000000
using namespace std;
int answer = INF;

void binary_search(int left, int right, double x, double y, int rate)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int new_rate = floor(((y + mid) * 100 / (x + mid)));
		if (new_rate != rate)
		{	
			right = mid - 1;
			answer = min(answer, mid);
		}
		else
		{
			left = mid + 1;
		}
	}
}

int main(void)
{
	double X, Y;
	cin >> X >> Y;
	int rate = floor(Y * 100 / X);
	binary_search(1, X, X, Y, rate);
	if (answer == INF)
		cout << -1 << '\n';
	else
		cout << answer << '\n';
}