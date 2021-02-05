#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	vector<int> digit;
	cin >> N;
	while (N > 0)
	{
		digit.push_back(N % 10);
		N /= 10;
	}
	sort(digit.begin(), digit.end(), greater<int>());
	for (int i = 0; i < digit.size(); i++)
	{
		cout << digit[i];
	}
}