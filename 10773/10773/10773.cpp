#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	stack<int> st;
	int K, num, sum = 0;;
	cin >> K;
	for(int i = 0; i < K; i++)
	{
		cin >> num;
		if (num == 0)
		{
			st.pop();
		}
		else
		{
			st.push(num);
		}
	}
	while(!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	cout << sum << "\n";
}