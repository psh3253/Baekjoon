#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int answer = 1;
	int N;
	cin >> N;
	vector<int> chu;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		chu.push_back(temp);
	}
	sort(chu.begin(), chu.end());
	int sum = 0;
	for (int i = 0; i < chu.size(); i++)
	{
		if (sum + 1 < chu[i])
		{
			break;
		}
		sum += chu[i];
	}
	if (sum != 0)
		answer = sum + 1;
	else
		answer = 1;
	cout << answer << '\n';
}