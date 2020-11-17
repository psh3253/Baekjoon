#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	int num, i, temp, sum = 0;
	stack<int> s;
	cin >> num;
	for (i = 0; i < num; i++)
	{
		cin >> temp;
		if (temp == 0)
			s.pop();
		else
			s.push(temp);
	}
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum << endl;
}