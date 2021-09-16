#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
	bool impossible = false;
	stack<int> st;
	vector<char> result;
	int n, num, current = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (!st.empty() && num == st.top())
		{
			st.pop();
			result.push_back('-');
		}
		else if (current <= num)
		{
			while(current < num)
			{
				st.push(current);
				current++;
				result.push_back('+');
			}
			if (num == current)
			{
				st.push(current);
				current++;
				result.push_back('+');
				st.pop();
				result.push_back('-');
			}
		}
		else
		{
			impossible = true;
		}
	}
	if (impossible)
		cout << "NO" << '\n';
	else
	{
		for(int i = 0 ; i < result.size(); i++)
		{
			cout << result[i] << '\n';
		}
	}
}