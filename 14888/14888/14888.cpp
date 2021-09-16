#include <iostream>
#include <algorithm>
using namespace std;
int N, max_value = -1000000001, min_value = 1000000001;
int num[11];
int temp;

void dfs(int plus, int minus, int multiplication, int division, int index, int sum)
{
	if(plus == 0 && minus == 0 && multiplication == 0 && division == 0)
	{
		min_value = min(min_value, sum);
		max_value = max(max_value, sum);
		return;
	}
	if(plus > 0)
	{
		dfs(plus - 1, minus, multiplication, division, index + 1, sum += num[index + 1]);
		sum -= num[index + 1];
	}
	if(minus > 0)
	{
		dfs(plus, minus - 1, multiplication, division, index + 1, sum -= num[index + 1]);
		sum += num[index + 1];
	}
	if(multiplication > 0)
	{
		dfs(plus, minus, multiplication - 1, division, index + 1, sum *= num[index + 1]);
		sum /= num[index + 1];
	}
	if(division > 0)
	{
		dfs(plus, minus, multiplication, division - 1, index + 1, sum /= num[index + 1]);
		sum *= num[index + 1];
	}
}

int main(void)
{
	int plus, minus, multiplication, division;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	cin >> plus >> minus >> multiplication >> division;
	dfs(plus, minus, multiplication, division, 0, num[0]);
	cout << max_value << endl;
	cout << min_value << endl;
}