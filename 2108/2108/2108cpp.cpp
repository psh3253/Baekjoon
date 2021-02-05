#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int number[500000];
int numberCount[8001];

int main(void)
{
	int N;
	int sum = 0;
	int maxCount = 0;
	vector<int> mode;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &number[i]);
		sum += number[i];
		numberCount[4000 + number[i]] += 1;
	}
	sort(number, number + N);
	printf("%.0lf\n", (double)sum / N);
	if (N % 2 == 0)
		cout << number[N / 2 + 1] << endl;
	else
		cout << number[N / 2] << endl;
	for (int i = 0; i < 8001; i++)
	{
		maxCount = max(maxCount, numberCount[i]);
	}
	for (int i = 0; i < 8001; i++)
	{
		if (numberCount[i] == maxCount)
		{
			mode.push_back(i - 4000);
		}
	}
	sort(mode.begin(), mode.end());
	if (mode.size() == 1)
		cout << mode[0] << endl;
	else
		cout << mode[1] << endl;
	cout << number[N - 1] - number[0] << endl;
}