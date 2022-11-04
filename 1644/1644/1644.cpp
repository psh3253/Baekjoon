#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long water[100000];
long long min_water = 2000000000;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int water_1, water_2;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> water[i];
	}
	sort(water, water + n);
	int start = 0;
	int end = n - 1;
	while(start != end)
	{
		if (abs(water[start] + water[end]) < min_water)
		{
			water_1 = water[start];
			water_2 = water[end];
			min_water = abs(water_1 + water_2);
			if (min_water == 0)
				break;
		}
		if (water[start] + water[end] < 0)
			start++;
		else if (water[start] + water[end] > 0)
			end--;
	}
	cout << water_1 << " " << water_2 << '\n';
}