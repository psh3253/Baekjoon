#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> weight;

int main(void)
{
	int temp;
	int answer = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		weight.push_back(temp);
	}
	sort(weight.begin(), weight.end());
	for (int i = 0; i < weight.size(); i++)
	{
		answer = max(answer, weight[i] * (int)(weight.size() - i));
	}
	cout << answer << '\n';
}